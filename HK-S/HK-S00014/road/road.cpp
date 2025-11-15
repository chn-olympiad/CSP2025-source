#include <bits/stdc++.h>
using namespace std;
ifstream fin ("road.in");
ofstream fout ("road.out");
typedef long long ll;
int main() {
    int n, m, k; fin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + k + 1);
    while (m--) {
        int u, v, w; fin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll ans = 0;
    vector<bool> vis(n + k + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while (!q.empty()) {
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        ans += cost;
        for (int i = 0; i < g[cur].size(); i++) {
            if (vis[g[cur][i].first]) continue;
            q.push({g[cur][i].second, g[cur][i].first});
        }
    }
    fout << (k? 0LL : ans) << '\n';
}