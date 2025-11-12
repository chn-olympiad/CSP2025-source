#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 105, K = 11;
const long long inf = 1e18;

int n, m, k, fa[N];

int find(int x) {
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

vector< array<int, 3> > get(vector< array<int, 3> > E) {
    for (int i = 1; i <= n + k; ++i) fa[i] = i;
    vector< array<int, 3> > res;
    for (auto [v, x, y] : E) {
        if (find(x) != find(y)) res.push_back({v, x, y}), fa[find(x)] = find(y);
    }
    return res;
}

int c[K];
vector< array<int, 3> > val[K];
long long res = inf;

void dfs(int s, int t, long long cur, vector< array<int, 3> > E) {
    if (s > t) {
        for (auto [v, x, y] : E) cur += v;
        res = min(res, cur);
        return;
    }
    dfs(s + 1, t, cur, E);
    vector< array<int, 3> > tE(E.size() + val[s].size());
    merge(E.begin(), E.end(), val[s].begin(), val[s].end(), tE.begin());
    dfs(s + 1, t, cur + c[s], get(tE));
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    vector< array<int, 3> > E;
    for (int i = 1, x, y, v; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &v);
        E.push_back({v, x, y});
    }
    sort(E.begin(), E.end()), E = get(E);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &c[i]);
        val[i].resize(n);
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &val[i][j - 1][0]);
            val[i][j - 1][1] = i + n, val[i][j - 1][2] = j;
        }
        sort(val[i].begin(), val[i].end());
    }
    dfs(1, k, 0, E);
    printf("%lld\n", res);
    return 0;
}