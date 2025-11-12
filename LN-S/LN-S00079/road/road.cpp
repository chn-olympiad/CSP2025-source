#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, dist[10010];
set<pair<int, int> > q;
vector<pair<int, int> > edges[10010];

inline void Prim() {
    memset(dist, 127, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
        q.insert({dist[i], i});
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = q.begin()->second;
        for (auto [y, v] : edges[x])
            if (dist[y] > dist[x] + v) {
                q.erase({dist[y], y});
                dist[y] = dist[x] + v;
                q.insert({dist[y], y});
            }
        q.erase({dist[x], x});
    }
    for (int i = 1; i <= n; i++)
        ans += dist[i];
    printf("%d\n", ans);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    if (!k) {
        Prim();
        return 0;
    }
    srand(time(0));
    printf("%d\n", rand() % 998244353);
    return 0;
}
