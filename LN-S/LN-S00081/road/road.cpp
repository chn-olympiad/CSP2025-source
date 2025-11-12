#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second

using namespace std;

const int N = 1e4 + 50, M = 1e6 + 50, p = 998244353;

int n, m, k, c[15], a[15][N];
pair <int, pii> b[M], d[N];
int fa[N], dist[N], vis[N];
vector <pii> e[N];
set <pii> q;

void init() {

}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
}

void kruskal() {
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(b + 1, b + m + 1);
    int l = 0;
    for (int i = 1; i <= m; i++)
        if (merge(b[i].se.fi, b[i].se.se))
            d[++l] = b[i];
    m = l;
    for (int i = 1; i <= m; i++) {
        e[d[i].se.fi].push_back({d[i].se.se, d[i].fi});
        e[d[i].se.se].push_back({d[i].se.fi, d[i].fi});
        //cerr << "edge " << i << " : " << d[i].se.fi << " " << d[i].se.se << endl;
    }
}

ll prim(int bit) {
    q.clear();
    for (int i = 1; i <= n + k; i++)
        dist[i] = 1 << 30, vis[i] = 0;
    dist[1] = 0;
    vis[1] = 1;
    for (int i = 1; i <= n + k; i++) q.insert({dist[i], i});
    ll ans = 0;
    //cerr << "!!!" <<endl;
    while (!q.empty()) {
        int u = q.begin()->se;
        q.erase(q.begin());
        if (dist[u] > 1000000050) break;
        //cerr << u << " " << dist[u] << endl;
        vis[u] = 1;
        ans += dist[u];
        for (auto _ : e[u]) {
            int v = _.fi, w = _.se;
            if ((v <= n || (bit >> (v - n - 1) & 1)) && !vis[v]) {
                if (dist[v] > w) {
                    q.erase({dist[v], v});
                    dist[v] = w;
                    q.insert({dist[v], v});
                }
            }
            //cerr << v << "&&" << w << endl;
        }
    }
    return ans;
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        b[i] = {w, {u, v}};
    }
    kruskal();
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            e[j].push_back({n + i, a[i][j]});
            e[n + i].push_back({j, a[i][j]});
        }
    }
    ll ans = 1LL << 60;
    for (int i = 0; i < 1 << k; i++) {
        ll sum = 0;
        for (int j = 1; j <= k; j++)
            if (i >> (j - 1) & 1)
                sum += c[j];
        ll res = sum + prim(i);
        //cerr << i << " " << res << endl;
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    init();
    int t = 1;
    //scanf("%d", &t);
    while (t--) solve();
    return 0;
}
