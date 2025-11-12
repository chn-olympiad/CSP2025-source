#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e4 + 10, M = 1e6 + 10, MAXK = 15;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &i) const {
        return w < i.w;
    }
} E[M];

int n, m, k, fa[N], c[MAXK], sz[N], id[MAXK];
pii a[MAXK][N];
vector<Edge> e;
ll ans = 1e18;

int Find(int x) {
    return fa[x] ? fa[x] = Find(fa[x]) : x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w, E[i] = {u, v, w};
    }
    sort(E + 1, E + m + 1);
    for (int i = 1; i <= m; i++) {
        int u = Find(E[i].u), v = Find(E[i].v);
        if (u != v) fa[u] = v, e.push_back(E[i]);
    }
    fill(fa + 1, fa + n + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1, x; j <= n; j++) cin >> x, a[i][j] = {x, j};
        sort(a[i] + 1, a[i] + n + 1);
    }
    for (int i = 0; i < (1 << k); i++) {
        ll res = 0;
        for (int j = 1; j <= n + k; j++) fa[j] = 0, sz[j] = 1;
        for (int j = 1; j <= k; j++) if (i & (1 << (j - 1))) res += c[j];
        fill(id + 1, id + k + 1, 1), id[k + 1] = 0;
        while (1) {
            int mmin = -1;
            for (int j = 1; j <= k; j++) {
                if ((i & (1 << (j - 1))) && id[j] <= n) {
                    if (mmin == -1 || a[mmin][id[mmin]].first > a[j][id[j]].first) mmin = j;
                }
            }
            if (id[k + 1] < e.size() && (mmin == -1 || a[mmin][id[mmin]].first > e[id[k + 1]].w)) mmin = k + 1;
            if (mmin == -1) break;

            int u = 0, v = 0, w = 0;
            if (mmin == k + 1) w = e[id[k + 1]].w, u = e[id[k + 1]].u, v = e[id[k + 1]].v, id[k + 1]++;
            else w = a[mmin][id[mmin]].first, u = mmin + n, v = a[mmin][id[mmin]].second, id[mmin]++;
            u = Find(u), v = Find(v);
            if (u != v) {
                if (sz[u] > sz[v]) swap(u, v);
                fa[u] = v, sz[v] += sz[u], res += w;
            }
        }
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
