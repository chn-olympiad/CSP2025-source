#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

const int MAXN = 1e4 + 50, MAXM = 1e6 + 50;
int n, m, k, cnt, fa[MAXN], g[15][MAXN], ans;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &o) { return w < o.w; }
} e[MAXM], e1[MAXN], e2[MAXM];

int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    fa[get(x)] = y;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= k; i++) {
        cin >> g[i][0];
        for (int j = 1; j <= n; j++) cin >> g[i][j];
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = e[i];
        if (get(u) == get(v)) continue;
        ans += w;
        e1[++cnt] = e[i];
        merge(u, v);
    }
    assert(cnt == n - 1);
    for (int st = 0; st < (1 << k); st++) {
        int res = 0, nw = n - 1;
        memcpy(e2 + 1, e1 + 1, sizeof(Edge) * (n - 1));
        for (int i = 1; i <= k; i++) {
            if (st >> (i - 1) & 1) {
                res += g[i][0];
                for (int j = 1; j <= n; j++) e2[++nw] = {i + n, j, g[i][j]};
            }
        }
        for (int i = 1; i <= n + k; i++) fa[i] = i;
        sort(e2 + 1, e2 + 1 + nw);
        for (int i = 1; i <= nw; i++) {
            auto [u, v, w] = e2[i];
            if (get(u) == get(v)) continue;
            res += w;
            merge(u, v);
        }
        ans = min(res, ans);
    }
    cout << ans << '\n';

    return 0;
}