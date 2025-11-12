#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353,N = 5005;
int dp[N][N],a[N];
signed main(){
    freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
    int n,ans = 0;cin >> n;dp[0][0] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= N-4;j++){
            dp[i][j] += dp[i-1][j],dp[i][j]%=mod;
            dp[i][min(N-4,j+a[i])] += dp[i-1][j],dp[i][min(N-4,j+a[i])]%=mod;
            if(j > a[i]) ans += dp[i-1][j],ans %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}
