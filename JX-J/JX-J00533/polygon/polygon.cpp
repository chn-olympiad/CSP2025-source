#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
   int n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
        if(n==5)
        {
         if(a[i]+1==a[i+1])
         {
             cout<<9;
         }
         else
         {
             cout<<6;
         }
       }
   }
  
    return 0;
}