#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=998244353;
int n,ans;
int a[N],po[N],dp[N];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    po[0]=1;
    for(int i=1;i<=n;i++) po[i]=(po[i-1]*2)%mod;
    sort(a+1,a+1+n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=0;j<=a[i];j++) res=(res+dp[j])%mod;
        ans=(ans+po[i-1]-res+mod)%mod;
        for(int j=5000;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
