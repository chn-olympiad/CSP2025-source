#include <bits/stdc++.h>
int main() {
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;
        edges.emplace_back(x, y, z);
    }
    std::vector<int> c(k);
    std::vector<std::vector<int>> d(k, std::vector<int>(n));
    for (int i = 0; i < k; i++) {
        std::cin >> c[i];
        for (int j = 0; j < n; j++)
            std::cin >> d[i][j];
    }
    std::sort(edges.begin(), edges.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool { return std::get<2>(x) < std::get<2>(y); });
    std::vector<int> p(n, -1);
    std::function<int(int)> find_set = [&](int x) -> int {
        if (!~p[x])
            return x;
        return p[x] = find_set(p[x]);
    };
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<std::tuple<int, int, int>> e;
    long long ans = 0;
    for (auto [u, v, w] : edges) {
        if (find_set(u) != find_set(v)) {
            p[find_set(u)] = find_set(v);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            e.emplace_back(u, v, w);
            ans += w;
        }
    }
    for (int l = 0; l < 1 << k; l++) {
        std::vector<std::tuple<int, int, int>> es(e);
        long long res = 0;
        for (int i = 0; i < k; i++) {
            if ((l >> i) & 1) {
                res += c[i];
                for (int j = 0; j < n; j++)
                    es.emplace_back(n + i, j, d[i][j]);
            }
        }
        std::sort(es.begin(), es.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool { return std::get<2>(x) < std::get<2>(y); });
        std::vector<int> p(n + k, -1);
        std::function<int(int)> find_set = [&](int x) -> int {
            if (!~p[x])
                return x;
            return p[x] = find_set(p[x]);
        };
        for (auto [u, v, w] : es) {
            if (find_set(u) != find_set(v)) {
                p[find_set(u)] = find_set(v);
                res += w;
            }
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';
    return 0;
}