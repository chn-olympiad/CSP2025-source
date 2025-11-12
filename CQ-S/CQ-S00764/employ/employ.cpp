#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define DBG(p) freopen(#p".in", "r", stdin), freopen("my.out", "w", stdout)
// #define int long long
#define LL long long
const int N = 19, mod = 998244353;
using namespace std;
int n, m, ans, c[N];
int p[N];
bool v[N];
string s;
void dfs(int x) {
    if (x == n+1) {
        int cnt = 0;
        rep(i, 1, n) {
            if (c[p[i]] <= cnt || s[i-1]=='0') ++cnt;
        }
        ans += n-cnt >= m;
    }
    rep(i, 1, n) {
        if (v[i]) continue;
        p[x] = i, v[i] = 1;
        dfs(x+1);
        v[i] = 0;
    }
}
signed main() {
    FASTIO;
    FRE(employ);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    dfs(1);
    cout << ans << '\n';
    return 0;
}