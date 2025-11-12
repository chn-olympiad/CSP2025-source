#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int mod=998244353;
int a[maxn];
long long dp[maxn][maxn];
int n,mx;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    sort(a+1,a+n+1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=mx+1;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            int t=max(0,j-a[i]);
            dp[i][j]=(dp[i][j]+dp[i-1][t])%mod;
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=mx+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    long long ans=0;
    for(int i=3;i<=n;i++){
        ans=(ans+dp[i-1][a[i]+1])%mod;
    }
    cout<<ans%mod;
    return 0;
}
