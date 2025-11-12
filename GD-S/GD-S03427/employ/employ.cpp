# include <bits/stdc++.h>
# define inf 0x3f3f3f3f
# define mod 998244353
# define mem(a, val) memset(a, val, sizeof(a))
# define rep(i, j, k) for(int i = j; i <= k; ++i)
# define per(i, j, k) for(int i = j; i >= k; --i)
using namespace std;

int n, m;
int s[505], c[505];
int dp[1 << 18][19];

inline int Mod(int x) {return x >= mod ? x - mod : x;}
inline void MOD(int &x, int y) {x = Mod(x + y);}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {char ch; cin >> ch; s[i] = ch == '1';}
    rep(i, 1, n) cin >> c[i];
    if(n == m) {
        bool flag = 1;
        rep(i, 1, n) if(s[i] == 0) flag = 0;
        rep(i, 1, n) if(c[i] == 0) flag = 0;
        if(flag) {int mul = 1; rep(i, 1, n) mul = 1ll * mul * i % mod; cout << mul << '\n';}
        else cout << "0\n";
        return 0;
    }
    dp[0][0] = 1;
    rep(S, 0, (1 << n) - 2) {
        int day = __builtin_popcount(S);
        rep(i, 0, day) {
            rep(j, 1, n) if((S & (1 << j - 1)) == 0) {
                if(s[day + 1] == 0 || i >= c[j]) MOD(dp[S ^ (1 << j - 1)][i + 1], dp[S][i]);
                else MOD(dp[S ^ (1 << j - 1)][i], dp[S][i]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, n) if(n - i >= m) ans = Mod(ans + dp[(1 << n) - 1][i]);
    cout << ans << '\n';
    return 0;
}