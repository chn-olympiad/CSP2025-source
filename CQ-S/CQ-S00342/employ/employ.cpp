#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 505, M = 18, mod = 998244353;
ll qpow(ll a, ll b) {ll ans = 1; while(b) {if(b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1;} return ans;}
ll fct[N], inv[N];
ll A(int n, int m) {if(n < m) return 0; return fct[n] * inv[n - m] % mod;}
ll C(int n, int m) {if(n < m) return 0; return A(n, m) * inv[m] % mod;}
int n, m, a[N], c[N], cnt[N];
namespace Subtask1 {
    int dp[1 << 18][20];
    void solve() {
        dp[0][0] = 1;
        for(int s = 0; s < (1 << n); s++) {
            int lim = __builtin_popcount(s);
            for(int j = 0; j <= lim; j++) {
                for(int k = 1; k <= n; k++) if(!((s >> k - 1) & 1)) {
                    int s_ = s | (1 << k - 1);
                    if(a[lim + 1] == 0 || c[k] <= lim - j) dp[s_][j] = (dp[s_][j] + dp[s][j]) % mod;
                    else dp[s_][j + 1] = (dp[s_][j + 1] + dp[s][j]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = m; i <= n; i++) ans = (ans + dp[(1 << n) - 1][i]);
        cout<<ans<<'\n';
    }
}
namespace Subtask2 {
    int dp[N][N];
    void solve() {
        dp[0][0] = fct[cnt[0]];
        for(int i = 1, sm = cnt[0]; i <= n; i++) {
            for(int j = 0; j <= sm; j++) {
                for(int k = 0; k <= cnt[i]; k++) {
                    if(cnt[i] != k && sm - j < i) continue;
                    int del = sm - j, p = sm - (del - i + 1);
                    ll tmp = dp[i - 1][j];
                    if(del < i) {
                        if(cnt[i] == k) tmp = tmp * A(sm + k, k) % mod; 
                    } else {
                        tmp = tmp * C(p + k, k) % mod * C(del - i + cnt[i] - k, cnt[i] - k) % mod * fct[cnt[i]] % mod;
                    }
                    dp[i][j + k] = (dp[i][j + k] + tmp) % mod;
                    // cerr<<i - 1<<' '<<j<<"->"<<i<<' '<<j + k<<' '<<tmp<<'\n';
                }
            }
            sm += cnt[i];
        }
        int ans = 0;
        for(int i = m; i <= n; i++) ans = (ans + dp[n][i]) % mod;
        cout<<ans<<'\n';
    }
}
inline void SOLVE() {
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        char c; cin>>c;
        a[i] = c - '0';
    }
    for(int i = 1; i <= n; i++) cin>>c[i], cnt[c[i]]++;
    if(n <= 18) return Subtask1::solve(), void();
    Subtask2::solve();
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for(int i = fct[0] = inv[0] = 1; i < N; i++) fct[i] = fct[i - 1] * i % mod, inv[i] = qpow(fct[i], mod - 2);
    int t = 1;
    while(t--) SOLVE();
    cerr<<clock() * 1.0 / CLOCKS_PER_SEC<<'\n';
    return 0;
}
//g++ -o -std=c++14 -O2 -DddxrS; ./