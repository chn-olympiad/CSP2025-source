#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],dp[25000005],mx,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++) cin>>a[i],mx+=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=a[i]+1;j<=mx;j++) ans=(1LL*ans+dp[j])%mod;
        for(int j=mx;j>=a[i];j--) dp[j]=(1LL*dp[j]+dp[j-a[i]])%mod;
    }
    cout<<ans;
    return 0;
}
