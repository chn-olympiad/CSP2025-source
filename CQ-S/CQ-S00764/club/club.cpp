#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define DBG(p) freopen(#p".in", "r", stdin), freopen("my.out", "w", stdout)
#define int long long
#define LL long long
const int N = 2e5+5, mod = 998244353;
using namespace std;
int n;
int a[N], b[N], c[N];
inline void solve() {
    cin >> n;
    int ans = 0;
    priority_queue<int> qa, qb, qc;
    rep(i, 1, n) {
        cin >> a[i] >> b[i] >> c[i];
        int t = max({a[i], b[i], c[i]});
        ans += t;
        if (t == a[i]) qa.push(-min(a[i]-b[i], a[i]-c[i]));
        else if (t == b[i]) qb.push(-min(b[i]-a[i], b[i]-c[i]));
        else qc.push(-min(c[i]-a[i], c[i]-b[i]));
    }
    while (qa.size() > (n>>1)) ans+=qa.top(),qa.pop();
    while (qb.size() > (n>>1)) ans+=qb.top(),qb.pop();
    while (qc.size() > (n>>1)) ans+=qc.top(),qc.pop();
    cout << ans << '\n';
}
signed main() {
    FASTIO;
    FRE(club);
    int _; cin >> _;
    while (_--) solve();
    return 0;
}