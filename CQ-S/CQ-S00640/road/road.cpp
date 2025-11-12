#include <bits/stdc++.h>

void IO(const std::string & s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;

constexpr int N = 2E4 + 5;

int n, m, k;

int fa[N], siz[N], c[N], a[11][N];
int find(int u) {
    return fa[u] == u? u: fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (siz[u] > siz[v]) {
        std::swap(u, v);
    }
    fa[u] = v;
    siz[v] += siz[u];
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }
}

std::vector<std::tuple<int, int, int>> edge, can_be;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    IO("road");

    std::cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }

    bool ok = true;
    for (int i = 1; i <= k; i++) {
        std::cin >> c[i];
        bool f = false;
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            if (a[i][j] == 0) {
                f = true;
            }
        }
        ok = (ok && c[i] == 0);
    }

    if (ok) {
        init(n + k);

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                edge.emplace_back(a[i][j], n + i, j);
            }
        }
    
        std::sort(edge.begin(), edge.end());

        i64 ans = 0;
        for (auto [w, u, v] : edge) {
            if (find(u) != find(v)) {
                ans += w;
                merge(u, v);
            }
        }
    
        std::cout << ans << "\n";
        return 0;
    }

    init(n);

    std::sort(edge.begin(), edge.end());

    i64 ans = 0;
    for (auto [w, u, v] : edge) {
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
            can_be.emplace_back(w, u, v);
        }
    }

    for (int mask = 0; mask < (1 << k); mask++) {
        i64 sum = 0;
        edge = can_be;
        int v = n;
        for (int i = 1; i <= k; i++) {
            if ((mask >> i - 1) & 1) {
                v++;
                sum += c[i];
                for (int j = 1; j <= n; j++) {
                    edge.emplace_back(a[i][j], i + n, j);
                }
            }
        }

        std::sort(edge.begin(), edge.end());
        init(n + k);

        int cnt = 0;
        for (auto [w, u, v] : edge) {
            if (find(u) != find(v)) {
                sum += w;
                cnt++;
                merge(u, v);
            }
            if (cnt == n + v - 1) break;
        }
        ans = std::min(ans, sum);
    }

    std::cout << ans << "\n";
    return 0;
}