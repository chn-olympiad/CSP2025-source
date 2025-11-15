#include <bits/stdc++.h>

int main() {
    std::ifstream input("road.in");
    std::ofstream output("road.out");
    int n, m, k;
    input >> n >> m >> k;
    std::vector<std::vector<std::pair<int, long long>>> adj(n, std::vector<std::pair<int, long long>>());

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        input >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // assume k = 0 or special A

    int special = 1;
    long long a[k][n];
    std::vector<long long> c(n);
    for (int i = 0; i < k; i++) {
        input >> c[i];
        if (c[i] != 0) special = 0;
        int test = 0;
        for (int j = 0; j < n; j++) {
            input >> a[i][j];
            if (a[i][j] == 0) test = 1;
        }
        if (test == 0) special = 0;
    }

    if (special) {
        for (int i = 0; i < k; i++) {
            int cc = -1;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    cc = j;
                }
            }
            for (int j = 0; j < n; j++) {
                if (j != cc) {
                    adj[cc].push_back({j, a[i][j]});
                    adj[j].push_back({cc, a[i][j]});
                }
            }
        }
    }

    if (k == 0 || special) {
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        pq.push({0, 0});
        std::vector<int> vis(n, 0);
        long long ans = 0;

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (vis[u]) continue;
            vis[u] = 1;
            ans += d;

            for (auto tmp : adj[u]) {
                int v = tmp.first;
                long long w = tmp.second;
                if (!vis[v]) {
                    pq.push({w, v});
                }
            }
        }
        output << ans << "\n";
    } else if (k == 5) {
        for (int b = 0; b<32;b++) {



    std::vector<std::vector<std::pair<int, long long>>> add(n+6, std::vector<std::pair<int, long long>>());

        for (int kk = 0; kk < 5; kk++) {
            if (b & (1 << kk)) {
                for (int g = 0; g < n; g++) {
                    add[n+kk].push_back({g, c[kk] + a[kk][g]});
                    add[g].push_back({n+kk, c[kk] + a[kk][g]});
                }
            }
        }

            
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        pq.push({0, 0});
        std::vector<int> vis(n, 0);
        long long ans = 0;

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (vis[u]) continue;
            vis[u] = 1;
            ans += d;

            for (auto tmp : adj[u]) {
                int v = tmp.first;
                long long w = tmp.second;
                if (!vis[v]) {
                    pq.push({w, v});
                }
            }
            for (auto tmp : add[u]) {
                int v = tmp.first;
                long long w = tmp.second;
                if (!vis[v]) {
                    pq.push({w, v});
                }
            }
        }
        output << ans << "\n";
        }
    }
}
