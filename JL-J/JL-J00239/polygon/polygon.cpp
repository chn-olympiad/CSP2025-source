#include<bits/stdc++.h>
using namespace std;
long long a[30000];
long long b[30000];
long long mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long i,n,j,ans,p;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
    }
    a[0]=1;
    ans=0;
    p=1;
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=b[i];j++)
        {
            ans-=a[j];
            ans%=mod;
        }
        ans+=p;
        ans%=mod;
        for(j=6000;j>=0;j--)
        {
            a[j+b[i]]+=a[j];
            a[j+b[i]]%=mod;
        }
        p*=2;
        p%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
    return 0;
}
