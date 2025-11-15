#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10005, M = 1000005;
int n, m, k, c[15], a[15][N], u[M], v[M], w[M];
vector<pair<int, pair<int, int>>> e[N];
bool A = 1;

int32_t main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        e[u[i]].push_back({i, {v[i], w[i]}});
        e[v[i]].push_back({i, {u[i], w[i]}});
    }
    if (k == 0) {
        int vis[N], viss[M];
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= m; i++) viss[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < e[1].size(); i++) {
            pq.push({e[1][i].second.second, e[1][i].first}); viss[e[1][i].first] = 1;
        }
        vis[1] = 1;
        int ans = 0;
        while (pq.size()) {
            pair<int, int> t = pq.top(); pq.pop();
            int ww = t.first;
            int uu = u[t.second];
            int vv = v[t.second];
            if (vis[vv]) swap(uu, vv);
            if (vis[vv]) continue;
            vis[vv] = 1;
            ans += ww;
            for (int i = 0; i < e[vv].size(); i++) {
                if (viss[e[vv][i].first]) continue;
                pq.push({e[vv][i].second.second, e[vv][i].first}); viss[e[vv][i].first] = 1;
            }
        }
        cout << ans << "\n";
    }
    else {
        for (int i = 1; i <= k; i++) {
            cin >> c[i];
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
    }
}