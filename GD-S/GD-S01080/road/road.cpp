#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k, u, v, w, sum = 0, c;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n + 11); // pair<int w, int u>
    vector<bool> fixed(n + 11, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        for (int j = 0; j < n; j++) {
            cin >> w;
            graph[n + i + 1].push_back({w, j + 1});
            graph[j + 1].push_back({w, n + i + 1});
        }
    }
    fixed[1] = true;
    for(auto [w, v] : graph[1]) {
        pq.push({w, v});
    }
    for (int i = 1; i < n + k; i++) {
        while (true) {
            auto [w, u] = pq.top();
            pq.pop();
            if (!fixed[u]) {
                fixed[u] = true;
                sum += w;
                for (auto [w, v] : graph[u]) {
                    pq.push({w, v});
                }
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}