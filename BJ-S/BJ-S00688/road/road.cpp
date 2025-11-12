#include <bits/stdc++.h>
using namespace std;
#define inlfc __attribute__((always_inline))
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 15, MAXX = 2e6;
int ecnt = 0, pcnt;
ll ans = 1e18;

struct Edge {
    int u, v, w, k;
} E[MAXX];

inlfc void add(int u, int v, int w, int k) {
    E[++ ecnt] = {u, v, w, k};
}

inlfc bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

struct Dsu {
    int f[MAXX];
    inlfc Dsu(int n) {
        for (int i = 1; i <= n; i ++) {
            f[i] = i;
        }
    }
    int find(int u) {
        return f[u] == u ? u : f[u] = find(f[u]);
    }
    inlfc bool chk(int u, int v) {
        return find(u) == find(v);
    }
    inlfc void merge(int u, int v) {
        if (chk(u, v)) return;
        u = find(u);
        v = find(v);
        f[u] = v;
    }
};

int embled[MAXK] = {1}, c[MAXK];

inlfc ll kruskal() {
    ll ans = 0;
    Dsu dsu(ecnt);
    for (int i = 1; i <= ecnt; i ++) {
        auto [u, v, w, k] = E[i];
        if (!embled[k]) continue;
        if (dsu.chk(u, v)) continue;
        ans += w;
        dsu.merge(u, v);
    }
    return ans;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w, 0);
    }
    for (int i = 1; i <= k; i ++) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++) {
            int a;
            cin >> a;
            add(i + n, j, a, i);
        }
    }
    sort(E + 1, E + ecnt + 1, cmp);
    for (int i = 0; i < 1 << k; i ++) {
        ll base = 0, nem = 0;
        for (int j = 1; j <= k; j ++) {
            int used = (i & (1 << (j - 1))) >> (j - 1);
            embled[j] = used;
            base += used * c[j];
            nem += used;
        }
        pcnt = n + nem;
        ans = min(ans, kruskal() + base);
    }
    cout << ans;
    return 0;
}
