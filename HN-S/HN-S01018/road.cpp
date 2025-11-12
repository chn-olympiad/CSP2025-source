#include <bits/stdc++.h>
#define N 10015
#define M 1000005
#define K 10
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
int n, m, k, tot, c[K], a[K][10]; ll ans;
struct edge {int u, v, w; inline bool operator < (const edge &o) const {return w < o.w;}} E[M], e[110005];
struct
{
    int fa[N], siz[N];
    inline void init(int n) {iota(fa + 1, fa + n + 1, 1), fill(siz + 1, siz + n + 1, 1);}
    inline int find(int x) {return x != fa[x] ? fa[x] = find(fa[x]) : x;}
    inline void merge(int u, int v)
    {
        if ((u = find(u)) != (v = find(v)))
        {
            if (siz[u] > siz[v]) swap(u, v);
            fa[u] = v, siz[v] += siz[u];
        }
    }
} dsu;
inline void kruskal()
{
    sort(E + 1, E + m + 1), dsu.init(n);
    for (int i = 1; i <= m; ++ i)
        if (dsu.find(E[i].u) != dsu.find(E[i].v)) e[++ tot] = E[i], dsu.merge(E[i].u, E[i].v), ans += E[i].w;
}
signed main()
{
    file(road);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i) cin >> E[i].u >> E[i].v >> E[i].w;
    kruskal();
    for (int i = 0, j, w; i < k; ++ i)
    {
        cin >> c[i];
        for (j = 1; j <= n; ++ j) cin >> w, e[++ tot] = {i + n + 1, j, w};
    }
    sort(e + 1, e + tot + 1); ll res;
    for (int s = 1, i, ct; s < 1 << k; ++ s)
    {
        res = 0;
        for (i = 0; i < k; ++ i)
            if (s >> i & 1) res += c[i];
        if (res >= ans) continue;
        dsu.init(n + k), ct = n + __builtin_popcount(s) - 1;
        // cerr << s << ' ' << res << '\n';
        for (i = 1; i <= tot; ++ i)
            if (e[i].u <= n)
            {
                if (dsu.find(e[i].u) != dsu.find(e[i].v))
                {
                    dsu.merge(e[i].u, e[i].v), res += e[i].w;
                    if (!-- ct) break;
                    if (res >= ans) break;
                }
            }
            else if (s >> e[i].u - n - 1 & 1 && dsu.find(e[i].u) != dsu.find(e[i].v))
            {
                dsu.merge(e[i].u, e[i].v), res += e[i].w;
                if (!-- ct) break;
                if (res >= ans) break;
            }
        ckmin(ans, res);
    }
    return cout << ans, 0;
}