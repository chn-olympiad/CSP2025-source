#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int maxn = 20, mod = 998244353;
int n, m, c[maxn], f[2][1 << 18][maxn];
string b; vector<int> S[maxn];
constexpr bool in(int s, int i) {return s >> (i - 1) & 1;}
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.in","w",stdout);
    cin >> n >> m;
    cin >> b; b = " " + b;
    rep(i, 1, n) cin >> c[i];
    rep(i, 0, (1 << n) - 1) S[__builtin_popcountll(i)].push_back(i);
    f[0][0][0] = 1;
    auto add = [&](int &x, int y) {x = (x + y) % mod;};
    rep(i, 1, n) {
        for (auto s : S[i]) rep(j, 0, i - 1) f[i & 1][s][j] = 0;
        for (auto s : S[i - 1]) rep(j, 0, i - 1) rep(k, 1, n) if (!in(s, k)){
            int d = (i - j - 1 < c[k]) && (b[i] == '1');
            add(f[i & 1][s | (1 << (k - 1))][j + d], f[(i - 1) & 1][s][j]);
        }
    }
    int ans = 0;
    rep(j, m, n) add(ans, f[n & 1][(1 << n) - 1][j]);
    cout << ans << endl;
    return 0;
}