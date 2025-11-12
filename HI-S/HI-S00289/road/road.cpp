#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

struct DSU {
    const int n;
    vector<int> fa;

    DSU(int _n): n(_n), fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int getfa(int u) {
        return fa[u] == u ? u : (fa[u] = getfa(fa[u]));
    }

    bool merge(int x, int y) {
        int fx = getfa(x), fy = getfa(y);
        if(fx != fy) {
            fa[fy] = fx;
            return true;
        }
        return false;
    }
};

int main() {
#ifndef LOCAL
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> e;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    vector<int> c(n + 1);
    vector<vector<int>> a(k + 1, vector<int>(n + 1));
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            e.push_back({n + i, j, a[i][j]});
        }
    }
    sort(e.begin(), e.end());

    i64 ans = INF;

    auto solve = [&](int s) {
        i64 res = 0;
        vector<int> vis(k + 1);
        for(int i = 1; i <= k; i++) {
            if(!((s >> (i - 1)) & 1)) {
                continue;
            }
            vis[i] = 1;
            res += c[i];
        }

        DSU dsu(n + k);
        for(auto [u, v, w]: e) {
            if(u > n && !vis[u - n]) {
                continue;
            }
            if(dsu.merge(u, v)) {
                res += w;
            }
        }
        return res;
    };

    int st = 1 << k;
    for(int s = 0; s < st; s++) {
        ans = min(ans, solve(s));
    }

    cout << ans << '\n';

    return 0;
}
// 16:30