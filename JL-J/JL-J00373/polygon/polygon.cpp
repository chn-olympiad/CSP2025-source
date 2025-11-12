#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
const int mod=998244353;
int pow(int x,int y)
{
    if(y==0) return 1;
    int ans=pow(x,y/2);
    if(y%2==1) return ans*ans%mod*x%mod;
    else return ans*ans%mod;
}
int jc(int x)
{
    int ans=1;
    for(int i=2;i<=x;i++)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}
int C(int n,int m)
{
    return (jc(n)*pow((jc(n-m)*jc(m)),mod-2))%mod;
}
signed main()//36
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%lld",&n);
    if(n<=3)
    {
        if(n<=2)puts("0");
        else
        {
            int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            int sum=a+b+c;
            int mx=max({a,b,c});
            mx*=2;
//          printf("%lld %lld",sum,mx);
            if(sum>mx)
            {
                puts("1");
            }
            else
            {
                puts("0");
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld",&x);
    }
    int ans=0;
    for(int i=3;i<=n;i++)
    {
        ans+=C(n,i);
        ans%=mod;
    }
    printf("%lld",ans%mod);
}
