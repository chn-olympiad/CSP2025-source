#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int a[5005];
int sum[5005];
int dp[5005][20005];
int ans=0;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    dp[0][0]=1;
    dp[1][a[1]]=1;
    for(int i=2;i<=n;i++) for(int j=0;j<i;j++) for(int k=0;k<=sum[j];k++) if(dp[j][k]) dp[i][k+a[i]]=(dp[i][k+a[i]]+dp[j][k])%998244353;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=sum[n];j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    for(int i=1;i<=n;i++) for(int j=a[i]*2+1;j<=sum[i];j++) if(dp[i][j]) ans=(ans+dp[i][j])%998244353;
    cout<<ans;
    return 0; 
}
