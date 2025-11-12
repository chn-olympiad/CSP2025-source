#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,mod=998244353,sum,mx=0;
int a[5005];
int qp(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygen.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    if(n<=3)
    {
        if(n==3 && sum>(2*mx)) printf("1");
        else    printf("0");
        return 0;
    }
    ans=(qp(2,n)-n*(n-1)/2-n-1)%mod;
    printf("%lld",ans);
    return 0;
}
