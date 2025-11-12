#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

int n, m, k, dist[10005][10005], ans;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(dist, 0x3f, sizeof dist);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dist[j][k] = min(dist[j][i] + dist[j][k], dist[j][k]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= 1e9)
                ans += dist[i][j];
    cout << ans / n << endl;
    return 0;
}
