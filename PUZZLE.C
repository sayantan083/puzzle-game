#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"dos.h"
int compare(int*);
getkey()
{
 union REGS i,o;

 while(!kbhit())
     ;
 i.h.ah=0;
 int86(22,&i,&o);
 return(o.h.ah);
}
void main()
{
  int a[4][4]={
		3,4,15,7,
		8,10,2,11,
		14,3,6,13,
		12,9,5,0
	      },i,j,t,x,y=0,m,n;
clrscr();
printf("                           The Puzzle Game\n\n");
printf("Rules: You have to rearrange the puzzle in ascending order using arrow keys. You have to move numbers about the inetger zero.");
printf("\n\n                 Press any key to continue");
getch();
printf("\n\n");
for(i=0;i<4;i++)
{
 for(j=0;j<4;j++)
 {
  printf("%d ",a[i][j]);
 }
 printf("\n");
}
printf("\n");

i=3;j=3;
sos:
x=getkey();

switch(x)
{
case 77:
if(j>0)
{
t=a[i][j];
a[i][j]=a[i][j-1];
a[i][j-1]=t;
j--;
break;
}
else
goto sos;

case 80:
if(i>0)
{
t=a[i][j];
a[i][j]=a[i-1][j];
a[i-1][j]=t;
i--;
break;
}
else
goto sos;

case 75:
if(j<3)
{
t=a[i][j];
a[i][j]=a[i][j+1];
a[i][j+1]=t;
j++;
break;
}
else
goto sos;

case 72:
if(i<3)
{
t=a[i][j];
a[i][j]=a[i+1][j];
a[i+1][j]=t;
i++;
break;
}
else
goto sos;

case 1:
exit(0);
}
for(m=0;m<4;m++)
{
 for(n=0;n<4;n++)
 {
  printf("%d ",a[m][n]);
 }
 printf("\n");
}
printf("\n");
x=compare(a);
if(x==0)
{
y++;
goto sos;
}
else if(x==1)
{
 printf("                Congractulations ");
 printf("You have completed the challenge in %d attempts",y);

}
 getch();
}
int compare(int*a)
{
  int i;
    for(i=0;i<15;i++)
    {
      if(*(a+i)<*(a+i+1) && *(a+i)!=0 && *(a+i+1)!=0)
      continue;
      else
      break;
    }
if(i==15)
return 1;
else
return 0;
}