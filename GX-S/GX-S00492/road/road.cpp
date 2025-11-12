#include <iostream>
#include <vector>
#include <queue>

int n, m, k;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> dis;
std::vector<int> fa;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    graph.resize(n+1);
    dis.resize(n+1, 0x2f2f2f2f);
    fa.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    std::queue<int> q;
    q.push(1);
    dis[1] = dis[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : graph[u]) {
            if (v == fa[u]) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                fa[v] = u;
                q.push(v);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dis[i] - dis[fa[i]];
    }
    std::cout << ans << '\n';

    return 0;
}
