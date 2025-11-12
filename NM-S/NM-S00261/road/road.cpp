#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 15, M = 1e6 + 15;

vector<vector<int>> vt(N);
int g[N][N], c[15], vis[N], ans = INT_MAX, n, m, k;

void dfs(int p, int cnt, int num) {
    // cout << cnt << ' ' << num << '\n';
    if (cnt > ans) return;
    if (num == n) {
        ans = min(ans, cnt);
        return;
    }

    for (auto v : vt[p]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (v > n) {
                dfs(v, cnt + g[p][v] + c[v - n], num);
            } else {
                dfs(v, cnt + g[p][v], num + 1);
            }
            vis[v] = 0;
        }
    }
}

int main() {
    freopen("road4.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vt[v].push_back(u);
        vt[u].push_back(v);
        g[u][v] = g[v][u] = w;
    }

    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            int t; cin >> t;
            vt[n + i].push_back(j);
            vt[j].push_back(n + i);
            g[n + i][j] = g[j][n + i] = t;
        }
    }

    dfs(1, 0, 1);

    cout << ans;
    return 0;
}