#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, k, p[10011], sz[10011], ans = 1e18;
vector<array<int, 3>> oe;
vector<array<int, 3>> e;

void init() {
    for (int i = 1; i <= n + 10; i++) p[i] = i, sz[i] = 1;
}

int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v], p[v] = u;
    return true;
}

const int inf = 1e18;

vector<pair<int, int>> a[10];
int activ[10];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    oe.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> oe[i][0] >> oe[i][1] >> oe[i][2];
    }
    sort(oe.begin(), oe.end(), [] (auto xx, auto yy) {
        return xx[2] < yy[2];
    });
    init();
    for (int i = 0; i < m; i++) if (merge(oe[i][0], oe[i][1])) e.push_back(oe[i]);
    // for (int i = 0; i < e.size(); i++) {
    //     cout << "e " << e[i][0] << " " << e[i][1] << " " << e[i][2] << '\n';
    // }
    for (int i = 0; i < k; i++) {
        cin >> activ[i];
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            a[i].push_back({x, j});
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int bm = 0; bm < (1 << k); bm++) {
        init();
        int cost = 0;
        vector<int> idx;
        for (int i = 0; i < k; i++) if (bm & (1 << i)) idx.push_back(i), cost += activ[i];
        int S = idx.size();
        int merg = S + n - 1;
        vector<int> ptr(S+1, 0);
        for (int i = 0; i < S * n + n - 1; i++) {
            int mn = inf, pl = -1;
            for (int j = 0; j < S; j++) if (ptr[j] < n && mn > a[idx[j]][ptr[j]].first) {
                mn = a[idx[j]][ptr[j]].first;
                pl = j;
            }
            if (ptr[S] < n-1 && mn > e[ptr[S]][2]) {
                mn = e[ptr[S]][2];
                pl = S;
            }
            // cout << "chk: " << mn << " " << pl << '\n';
            if (pl != -1 && pl < S) {
                if (merge(a[idx[pl]][ptr[pl]].second, idx[pl] + n + 1)) {
                    cost += mn;
                    merg--;
                }
                ptr[pl]++;
            } else if (pl == S) {
                if (merge(e[ptr[S]][0], e[ptr[S]][1])) {
                    cost += mn;
                    merg--;
                }
                ptr[pl]++;
            }
            if (merg <= 0) break;
        }
        if (cost < ans) ans = cost;
        // for (int i = 0; i < S; i++) cout << idx[i] << " ";
        // cout << '\n';
        // cout << "cost: " << cost << '\n';
    }
    cout << ans << '\n';
}
