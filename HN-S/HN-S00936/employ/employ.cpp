#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 19, M = (1 << 18), mod = 998244353, K = 505;

int n, m, c[K], dp[M][N], ans;
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n; i++) cin >> c[i];
    if(m == n){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' || c[i] == 0){
                cout << 0;
                return 0;
            }
        }
        ans = 1;
        for(int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
        cout << ans;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i < (1 << n); i++){
        int cnt = 0;
        for(int j = 0; j < n; j++) if((i >> j) & 1) cnt++;
        for(int u = 0; u < n; u++){
            if((i >> u) & 1){
                for(int y = 0; y < min(c[u], cnt); y++){
                    if(s[cnt - 1] == '0'){
                        if(y) dp[i][y] += dp[i ^ (1 << u)][y - 1];
                    }else{
                        dp[i][y] += dp[i ^ (1 << u)][y];
                    }
                    if(dp[i][y] >= mod) dp[i][y] -= mod;
                }
                for(int y = c[u] + (s[cnt - 1] == '1'); y <= min(n, cnt); y++){
                    dp[i][y] += dp[i ^ (1 << u)][y - 1];
                    if(dp[i][y] >= mod) dp[i][y] -= mod;
                }
            }
        }
    }
    for(int j = n - m; j >= 0; j--){
        ans += dp[(1 << n) - 1][j];
        if(ans >= mod) ans -= mod;
    }
    cout << ans;
    return 0;
}
