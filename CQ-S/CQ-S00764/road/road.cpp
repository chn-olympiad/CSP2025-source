#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define DBG(p) freopen(#p".in", "r", stdin), freopen("my.out", "w", stdout)
#define int long long
// #define LL long long
const int N = 10015, M = 2e6+5, mod = 998244353;
using namespace std;
int n, m, k;
struct edge {
    int u, v, w, id;
} ed[M];
int tot, a[N], c[15][N];
int fa[N];
inline int get(int x) {
    return fa[x] == x ? x : (fa[x] = get(fa[x]));
}
inline bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    fa[y] = x;
    return true;
}
signed main() {
    FASTIO;
    FRE(road);
    cin >> n >> m >> k;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        ed[i] = {u, v, w, 0};
    } tot = m;
    bool flag = 1;
    rep(i, 1, k) {
        cin >> a[i]; flag &= a[i]==0;
        bool t = 0;
        rep(j, 1, n) cin >> c[i][j], t|= c[i][j];
        flag &= t;
    }
    iota(fa+1, fa+n+1, 1);
    if (flag) {
        rep(i, 1, k) {
            int id0 = 0;
            rep(j, 1, n) {
                if (c[i][j] == 0) {
                    id0 = j;
                    break;
                }
            }
            rep(j, 1, n) {
                if (j != id0) {
                    ed[++tot] = {id0, j, c[i][j], 0};
                }
            }
        }
        stable_sort(ed+1, ed+tot+1, [](const edge& a, const edge& b) { return a.w < b.w; });
        int ans = 0;
        rep(i, 1, tot) {
            if (merge(ed[i].u, ed[i].v)) ans += ed[i].w;
        }
        cout << ans << '\n';
        return 0;
    }
    rep(i, 1, k)
        rep(j, 1, n) {
            ed[++tot] = {i+n, j, c[i][j], i};
        }
    stable_sort(ed+1, ed+tot+1, [](const edge& a, const edge& b) { return a.w < b.w; });
    int res = LONG_LONG_MAX;
    for (int msk = 0; msk < 1<<k; ++msk) {
        int ans = 0;
        iota(fa+1, fa+n+k+1, 1);
        rep(i, 1, k) ans += (a[i])*(msk>>i-1&1);
        for (int i = 1; i <= tot; ++i) {
            if (!ed[i].id || (msk >> (ed[i].id-1) & 1)) {
                if (merge(ed[i].u, ed[i].v)) ans += ed[i].w;
            }
        }
        res = min(res, ans);
    }
    cout << res << '\n';
    return 0;
}