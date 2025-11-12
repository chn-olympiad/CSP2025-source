# include <bits/stdc++.h>
# define inf 0x3f3f3f3f
# define maxm 1001000
# define maxn 10100
# define ll long long
# define mem(a, val) memset(a, val, sizeof(a))
# define rep(i, j, k) for(int i = j; i <= k; ++i)
# define per(i, j, k) for(int i = j; i >= k; --i)
using namespace std;

struct Road {int u, v, w;} a[maxm], b[maxn * 11];
int n, m, k, num;
int fa[maxn], siz[maxn];
int c[15], d[15][maxn];
ll ans;

inline bool cmp(Road x, Road y) {return x.w < y.w;}
inline int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}
inline void merge(int x, int y) {
    x = Find(x); y = Find(y); if(x == y) return;
    if(siz[x] < siz[y]) swap(x, y); siz[x] += siz[y]; fa[y] = x;
}

inline void init() {
    rep(i, 1, n + k) fa[i] = i, siz[i] = 1;
}

inline bool check(int x, int S) {
    if(x <= n) return 1; x -= n;
    if(S & (1 << x - 1)) return 1; return 0;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    init();
    rep(i, 1, m) cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a + 1, a + m + 1, cmp);
    rep(i, 1, m) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if(Find(u) == Find(v)) continue;
        merge(u, v); ans += w; b[++num] = a[i];
    }
    rep(i, 1, k) {
        cin >> c[i];
        rep(j, 1, n) cin >> d[i][j], b[++num] = {n + i, j, d[i][j]};
    }
    sort(b + 1, b + num + 1, cmp);
    rep(S, 1, (1 << k) - 1) {
        init(); ll res = 0, cnt = 0, tot = n + __builtin_popcount(S);
        rep(i, 1, num) {
            int u = b[i].u, v = b[i].v, w = b[i].w;
            if(!check(u, S) || !check(v, S) || Find(u) == Find(v)) continue;
            res += w; merge(u, v); cnt++; if(cnt == tot - 1) break;
        }
        rep(i, 1, k) if(S & (1 << i - 1)) res += c[i];
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}