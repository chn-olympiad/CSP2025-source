#include <bits/stdc++.h>
using namespace std;
#define int long long

struct thing {
    int u, v, w;
    bool operator < (const thing &b) const {
        return w < b.w;
    }
};

const int maxn = 1e4 + 5, maxm = 1e6 + 5, maxk = 13, INF = 1e18;
int n, m, k;
vector<thing> EDGES, edges;
int a[maxk][maxn], c[maxk];

int dsu[maxn], sz[maxn];
int rt(int u) {
    if (u == dsu[u]) return u;
    return dsu[u] = rt(dsu[u]);
}
void merge(int u, int v) {
    u = rt(u), v = rt(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    dsu[u] = v;
    sz[v] += sz[u];
}

int calc() {
    for (int i=1;i<=n+k;i++) dsu[i] = i;
    sort(edges.begin(), edges.end());
    int ret = 0;
    for (thing x:edges) if (rt(x.u) != rt(x.v)) {
        merge(x.u, x.v);
        ret += x.w;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    EDGES.resize(m);
    for (thing &x:EDGES) cin >> x.u >> x.v >> x.w;
    for (int i=0;i<k;i++) {
        cin >> c[i];
        for (int j=1;j<=n;j++) cin >> a[i][j];
    }

    sort(EDGES.begin(), EDGES.end());
    for (int i=1;i<=n;i++) dsu[i] = i;
    edges.clear();
    for (thing x:EDGES) if (rt(x.u) != rt(x.v)) {
        merge(x.u, x.v);
        edges.push_back(x);
    }
    EDGES = edges;
    edges.clear();

    int ans = INF;
    for (int i=0;i<(1<<k);i++) {
        int curans = 0;
        edges = EDGES;
        for (int j=0;j<k;j++) if (i & (1<<j)) {
            curans += c[j];
            for (int ii=1;ii<=n;ii++) edges.push_back({n+1+j, ii, a[j][ii]});
        }
        curans += calc();
        ans = min(curans, ans);
    }

    cout << ans << '\n';
}