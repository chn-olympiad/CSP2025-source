#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 5e4 + 10, M = 5e6 + 10, K = 13;

using namespace std;

void Debug() {}

struct edge {
    int from, to;
    ll w;
};

bool vis[N];
int cnt;
int c[N];
int siz[N];
int dis[K][N];
edge e[N];
int n, m, k;
int fa[N];

void init(int x) {
    for (int i = 0; i <= x; ++i) fa[i] = i;
    for (int i = 0; i <= n; ++i) siz[i] = 1;
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    fa[v] = u;
    siz[u] += siz[v];
    return true;
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

ll kru() {
    memset(siz, 0, sizeof siz);
    memset(vis, 0, sizeof vis);
    sort(e + 1, e + 1 + cnt, cmp);
    init(n + k + 10);
    ll ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (merge(e[i].from, e[i].to)) {
            ans += e[i].w;
            vis[e[i].from] = true;
            if (siz[find(e[i].from)] == n) break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    init(n + k + 10);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        e[++cnt] = {u, v, w};
    }
    ll x = kru();
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) {
            cin >> dis[i][j];
            e[++cnt] = {n + i, j, dis[i][j]};
        }
    }
    ll y = kru();
    for (int i = 1; i <= k; ++i) {
        if (vis[i + n]) y += c[i];
    }
    cout << min(x, y) << '\n';
    return 0;
}
