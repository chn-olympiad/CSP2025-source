#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5006];
long long ans,dp[5006][5006],f[5006];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    f[0]=1LL;
    for (int i=1;i<=5000;i++) f[i]=f[i-1]*2%mod;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i]*=-1;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) a[i]*=-1;
    dp[n+1][0]=1;
    dp[n][0]=dp[n][a[n]]=1;
    for (int j=n-1;j>=1;j--){
        for (int k=0;k<=5000;k++){
            if (k>=a[j]) dp[j][k]+=dp[j+1][k-a[j]];
            dp[j][k]+=dp[j+1][k];
            dp[j][k]%=mod;
        }
    }
    for (int i=1;i<=n;i++){
        long long cnt=f[n-i];
        for (int j=0;j<=a[i];j++) cnt-=dp[i+1][j];
        ans+=cnt;
        ans+=mod;
        ans%=mod;
    }
    ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
