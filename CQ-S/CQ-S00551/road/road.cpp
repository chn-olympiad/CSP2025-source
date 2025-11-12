#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define debug(x) cerr << #x << ' ' << x << '\n'
using LL = long long;
constexpr int MAXN = 2e4 + 5, MAXM = 1e6 + 5;
struct node {
    int u, v, w;
    inline bool operator < (const node &o) const { return w < o.w; }
} E[MAXM], T[MAXM];
int n, m, k, tot, fa[MAXN], siz[MAXN], c[10];
inline void init() { for (int i = 1; i <= n + k; ++i) fa[i] = i, siz[i] = 1; }
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (siz[u] > siz[v]) swap(u, v);
    fa[u] = v, siz[v] += siz[u];
    return true;
}
inline bool check(int u, int sta) {
    if (u <= n) return true;
    u -= n + 1;
    return (sta >> u) & 1;
}
inline LL MST(int sta) {
    init();
    LL ret = 0;
    for (int i = 0; i < k; ++i) if ((sta >> i) & 1) ret += c[i];
    int cur = n + __builtin_popcount(sta) - 1;
    for (int i = 1; i <= tot; ++i) {
        if (!check(T[i].u, sta) || !check(T[i].v, sta)) continue;
        if (merge(T[i].u, T[i].v)) ret += T[i].w, --cur;
        if (!cur) break;
    }
    return ret;
}
int main() {
    IOS;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    init();
    for (int i = 1; i <= m; ++i) cin >> E[i].u >> E[i].v >> E[i].w;
    sort(E + 1, E + 1 + m);
    LL ans = 0;
    for (int i = 1; i <= m; ++i) if (merge(E[i].u, E[i].v)) T[++tot] = E[i], ans += E[i].w;
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        for (int j = 1, x; j <= n; ++j) cin >> x, T[++tot] = {i + 1 + n, j, x};
    }
    sort(T + 1, T + 1 + tot);
    for (int S = 0; S < (1 << k); ++S) ans = min(ans, MST(S));
    cout << ans << '\n';
    return 0;
}