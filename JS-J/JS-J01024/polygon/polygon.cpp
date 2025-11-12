#include "bits/stdc++.h"
using namespace std;
int n;
int a[5005];
int sy[5005];
long long ans;
long long mo(int ss)
{
   long long an=1;
   for(int i=1;i<=ss;i++)
   {
       an*=2;
   }
   return an;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        sy[i]=sy[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=3;j<=n;j++)
        {

            if(sy[i]>a[j])
            {
                if(i!=1||j!=3)
                {
                    ans+=mo(j-i-1);
                }
            }
            ans%=998244353;
        }
    }
    cout<<ans-1;
    return 0;
}
