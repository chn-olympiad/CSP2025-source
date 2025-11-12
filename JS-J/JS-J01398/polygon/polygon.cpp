#include<bits/stdc++.h>
#define int long long
#define MAXN 5000
using namespace std;
int n,dp[5005],a[5005],ans=1,pw=1;
const int mod=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)pw=pw*2%mod;
    sort(a+1,a+n+1);dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++)ans=(ans+dp[j])%mod;
        for(int j=MAXN;j>=a[i];j--)dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }cout<<(pw-ans+mod)%mod;
}
