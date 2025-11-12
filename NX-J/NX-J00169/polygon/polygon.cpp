#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
   int n,s=0;
   cin>>n;
   for(int i=1;i<=n;i++)
   {

       cin>>a[i];
       s+=a[i];
   }
   cout<<s;
    return 0;
}

