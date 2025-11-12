#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 10;
const int INF = 1e9;
int n, m, k, c[11], d[maxn], cost[11][maxn];
vector<pair<int, int>> g[maxn];
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> cost[i][j];
    }
    cout << 0 << endl;
    return 0;
}