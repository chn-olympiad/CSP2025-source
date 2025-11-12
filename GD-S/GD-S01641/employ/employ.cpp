#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 505
const int MOD(998244353);

int n, m; string s; int c[MAXN];

namespace sol1{  // n <= 18
    int f[1<<18][19], g[1<<18][19];
    void sol(){
        f[0][0] = 1;
        for (int i(1); i<=n; ++i){
            memset(g, 0, sizeof(g));
            for (int S(0); S<(1<<n); ++S) if (__builtin_popcount(S) == i-1){
                for (int j(0); j<i; ++j) if (f[S][j]){
                    for (int k(0); k<n; ++k) if (!(S>>k&1)) (g[S|1<<k][j+(s[i]=='0'||c[k+1]<=j)] += f[S][j]) %= MOD;
                }
            }
            memcpy(f, g, sizeof(g));
        }
        int ans(0); for (int i(m); i<=n; ++i) (ans += f[(1<<n)-1][n-i]) %= MOD; cout << ans;
    }
}
namespace sol2{  // m = 1
    int ct[MAXN], C[MAXN][MAXN], fac[MAXN], f[MAXN][MAXN], sf[MAXN];
    void sol(){
        for (int i(0); i<MAXN; ++i){C[i][0]=1; for (int j(1); j<MAXN; ++j) C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;}
        fac[0] = 1; for (int i(1); i<MAXN; ++i) fac[i] = i*fac[i-1]%MOD;
        for (int i(n); ~i; --i) sf[i] = sf[i+1]+(s[i] == '1'); for (int i(1); i<=n; ++i) ++ct[c[i]]; f[n+1][0] = 1;
        for (int i(n), s(0); ~i; s += ct[i--]){
            for (int j(0); j<=s; ++j) for (int k(0); k<=ct[i]; ++k) if (sf[i+1] >= j+k){
                (f[i][j+k] += f[i+1][j]*C[sf[i+1]-j][k]%MOD*fac[k]%MOD*C[ct[i]][k]) %= MOD;
            }
        }
        // cerr << f[1][1] << ' ' << f[0][2] << '\n';
        int ans(1); for (int i(1); i<=n; ++i) (ans *= i) %= MOD; cout << (ans+MOD-f[0][sf[1]]*fac[n-sf[1]]%MOD)%MOD;
    }
}

signed main(){
    freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s; s = ' ' + s; for (int i(1); i<=n; ++i) cin >> c[i];
    if (n <= 18) sol1::sol(); else sol2::sol();

    return 0;
}