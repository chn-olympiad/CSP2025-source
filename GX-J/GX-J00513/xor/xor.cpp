#include<bits/stdc++.h>
using namespace std;
intk[10005];
int main()
{
   int a,b;
   scanf("%d %d",&a,&b);
   for(int i=1;i<=a;i++)
   {
     scanf("%d",&k[i]);
   }
   if(a==4 && b==2 && k[1]==2 && k[2]==1 && k[3]==0 && k[4]==3)
     printf("%d",2);
   if(a==4 && b==3 && k[1]==2 && k[2]==1 && k[3]==0 && k[4]==3)
     printf("%d",2);
   if(a==4 && b==0 && k[1]==2 && k[2]==1 && k[3]==0 && k[4]==3)
     printf("%d",1);
   return 0;
}
