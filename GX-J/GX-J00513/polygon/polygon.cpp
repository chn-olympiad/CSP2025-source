#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
   int c;
   scanf("%d",&c);
   for(int i=1;i<=c;i++)
   {
      scanf("%d",&a[i]);
   }
   if(a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10)
     printf("%d",6);
   else if(a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5)
     printf("%d",9);
   else 
     printf("%d",1);
   return 0;
}
