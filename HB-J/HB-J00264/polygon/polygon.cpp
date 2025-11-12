#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5, A=5e+5, mod=998244353;
int n, a[N];
int dp[N][A];
inline void init() {
    memset(dp, 0, sizeof(dp));
    for(int i=1, pre=0; i<=n; ++i) {
        pre+=a[i];
        for(int j=0; j<pre; ++j) {
            if(j>=a[i]) dp[i][j]=dp[i-1][0];
            else dp[i][j]=(dp[i-1][max(j-a[i], 0)]+1) %mod;
            cout<<i<<" "<<j<<"  "<<dp[i][j]<<'\n';
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    if(n==3) {
        int maxn=max(max(a[1], a[2]), a[3]);
        if(a[1]+a[2]+a[3]>maxn*2) cout<<1;
        else cout<<0;
        return 0;
    }
    sort(a+1, a+n+1);
    if(a[n]==1) {
        cout<<0;
        return 0;
    }
    init();
    long long ans=0;
    for(int i=3; i<=n; ++i) ans=(ans+dp[i][a[i]*2]) %mod;
    cout<<ans;
    return 0;
}