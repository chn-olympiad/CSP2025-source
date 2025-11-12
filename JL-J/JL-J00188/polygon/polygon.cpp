#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5100];
int n;
int maxn,s;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
   cin>>n;

   for(int i=1;i<=n;i++)
   {

       cin>>a[i];

       maxn=max(maxn,a[i]);
       s+=a[i];
   }
   if(n<3)
   {
       cout<<"0";
       return 0;
   }
   if(s>maxn*2)
   {
       cout<<"1";
   }
   else
   {
       cout<<"0";
   }

    return 0;
}
