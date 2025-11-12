#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int dp[2][maxn],n,a[maxn],o,maxx=-1,f[maxn],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    sort(a+1,a+n+1);
    f[1]=2;
    for(int i=2;i<=n;i++)
        f[i]=(long long)f[i-1]*2%mod;
    o=0;
    for(int j=0;j<a[1];j++)
        dp[o][j]=1;
    for(int i=2;i<=n;i++)
    {
        o^=1;
        for(int j=0;j<a[i];j++)
            dp[o][j]=(dp[o^1][j]+f[i-1])%mod;
        for(int j=a[i];j<=maxx;j++)
            dp[o][j]=(dp[o^1][j]+dp[o^1][j-a[i]])%mod;
        if(i>=3)
        {

            ans=(ans+dp[o^1][a[i]])%mod;
        }
    }
    cout<<ans;
    return 0;
}
