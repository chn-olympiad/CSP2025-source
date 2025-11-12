#include<bits/stdc++.h>
using namespace std;
long long n,a[5003],kid[5003],ans=1;
const long long mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        ans*=2;
        ans%=mod;
    }
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    kid[0]=1;
    ans--;
    ans%=mod;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=a[i];j++)
        {
            ans-=kid[j];
            ans%=mod;
        }
        for(long long j=5000;j>=a[i];j--)
        {
            kid[j]+=kid[j-a[i]];
            kid[j]%=mod;
        }
    }
    printf("%lld",(ans%mod+mod)%mod);
    return 0;
}
