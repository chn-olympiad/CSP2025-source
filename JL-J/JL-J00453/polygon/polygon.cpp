#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5100];
long long c[5100]={1};
long long pow(long long a,int c)
{
    if(c==0)
        return 1;
    long long tmp=pow(a,c/2);
    tmp=(tmp*tmp)%mod;
    if(c%2==1)
    {
        tmp=(tmp*a)%mod;
    }
    return tmp;
}
long long dp[1<<20],sta;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        c[i]=(c[i-1]*i)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long ans=0,x,y;
    for(int i=3;i<=n;i++)
    {
        x=pow(c[i],mod-2);
        y=pow(c[n-i],mod-2);
        ans=(ans+c[n]*x%mod*y%mod);
        //cout<<ans<<' '<<c[i]<<' '<<x<<' '<<y<<endl;
    }
    printf("%lld\n",ans);
    return 0;

}
