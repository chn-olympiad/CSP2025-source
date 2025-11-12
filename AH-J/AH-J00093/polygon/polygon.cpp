#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N];
long long dp[N][N],ans,f[N][N],g[N][N],mod=998224353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        dp[i][a[i]]++;
        g[i][a[i]]++;
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<i;j++){
            dp[i][a[j]]=(dp[i][a[j]]+dp[i-1][a[j]])%mod;
            g[i][a[j]]=(g[i-1][a[j]]+g[i][a[j]])%mod;
            if(a[j]*2>a[i])dp[i][a[i]]=(g[i-1][a[j]]+dp[i][a[i]])%mod;
            g[i][a[i]]=(g[i-1][a[j]]+g[i][a[i]])%mod;
            //cout<<i<<' '<<a[j]<<' '<<dp[i][a[j]]<<'\n';
        }
        //cout<<i<<' '<<a[i]<<' '<<dp[i][a[i]]<<'\n';
    }
    for(int i=1;i<=n;i++)ans=(ans+dp[n][a[i]])%mod;
    cout<<ans-n+1;
    return 0;
}
