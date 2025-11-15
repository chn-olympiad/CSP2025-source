#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7, inf = 1e18;
void solve() {
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> par(n+k), val(k), md(k, 0);
    vector<bool> vis(k, 0);
    vector<vector<pair<int, int>>> to(n+k);
    vector<vector<int>> cost(k, vector<int>(n));
    for (int i=0; i<n+k; i++) par[i] = i;
    auto find = [&](auto&& find, int x) -> int {
        if (par[x] != x) par[x] = find(find, par[x]);
        return par[x];
    };
    auto onion = [&](int a, int b) -> void {
        a = find(find, a), b = find(find, b);
        if (a != b) par[max(a, b)] = min(a, b);
        return;
    };
    priority_queue<pair<int, array<int, 2>>, vector<pair<int, array<int, 2>>>, greater<pair<int, array<int, 2>>>> edges, opq;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push({w, {u, v}});
    }
    for (int i=0; i<k; i++) {
        cin >> val[i];
        for (int j=0; j<n; j++) cin >> cost[i][j];
        for (int j=1; j<n; j++) if (cost[i][j] < cost[i][md[i]]) md[i] = j;
    }
    while (!edges.empty()) {
        int w = edges.top().first, u = edges.top().second[0], v = edges.top().second[1];
        int r = u, s = v;
        u = find(find, u), v = find(find, v);
        edges.pop();
        if (u != v) {
            to[r].push_back({s, w});
            to[s].push_back({r, w});
            opq.push({w, {r, s}});
            res += w;
            onion(u, v);
        }
    }
    int rr = (1ll<<k);
    for (int bm=1; bm<rr; bm++) {
        edges = opq;
        for (int i=0; i<n; i++) par[i] = i;
        int cur = 0;
        for (int j=0; j<k; j++) if (bm&(1ll<<j)) {
            cur += val[j];
            cur += cost[j][md[j]];
            for (int x=0; x<n; x++) if (x != md[j]) {
                edges.push({cost[j][x], {x, md[j]}});
            }
        }
        while (!edges.empty()) {
            int w = edges.top().first, u = edges.top().second[0], v = edges.top().second[1];
            int r = u, s = v;
            u = find(find, u), v = find(find, v);
            edges.pop();
            if (u != v) {
                cur += w;
                onion(u, v);
            }
        }
        res = min(res, cur);
        // cout << bm << ' ' << cur << '\n';
    }
    cout << res << '\n';
    return;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto frt = freopen("road.in", "r", stdin);
    auto frt2 = freopen("road.out", "w", stdout);
    solve();
    return 0;
}