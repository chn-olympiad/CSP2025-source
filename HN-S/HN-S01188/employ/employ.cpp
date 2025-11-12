#include <bits/stdc++.h>
using std::cin;

namespace solution {
    const int N = 25, N_ = 1 << 18, NN = 505, mod = 998244353;
    int f[N_][N], c[NN];
    int n, m;
    std::string s;
    void solve(){
        cin >> n >> m >> s, s = " " + s;
        for(int i=1;i<=n;i++) cin >> c[i];
        if(m == n){
            bool ok = true; int ans = 1;
            for(int i=1;i<=n;i++){
                ans = 1ll * ans * i % mod;
                ok &= (c[i] != 0 && s[i] == '1');
            }
            std::cout << (ok ? ans : 0) << '\n';
            return;
        }
        f[0][0] = 1;
        for(int S=0;S<(1<<n);S++){
            int len = __builtin_popcount(S);
            for(int i=0;i<=n&&i<=len;i++){
                for(int j=1;j<=n;j++){
                    if((S >> (j - 1)) & 1) continue;
                    int& nxt = f[S | (1 << (j - 1))][i + (len - i < c[j] && s[len + 1] != '0')];
                    nxt += f[S][i];
                    if(nxt >= mod) nxt -= mod;
                }
            }
        }
        int ans = 0;
        for(int i=m;i<=n;i++){
            ans += f[(1 << n) - 1][i];
            if(ans >= mod) ans -= mod;
        }
        std::cout << ans << '\n';
    }
}

signed main(){
    #ifndef LOCAL
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    solution::solve();
    return 0;
}

// think twice, code once
// Writting by xiezheyuan
