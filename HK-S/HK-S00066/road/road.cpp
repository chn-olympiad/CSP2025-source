#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<array<int, 3>> eds, eds2;
const int N = 1e4 + 20;

int par[N];
int find(int n) {return par[n] == n ? n : par[n] = find(par[n]);}

int32_t main(){
    ifstream cin("road.in");
    ofstream cout("road.out");
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        eds.emplace_back((array<int, 3>) {w, u, v});
    }
    sort(eds.begin(), eds.end());
    for (auto vec : eds) {
        int w = vec[0], u = vec[1], v = vec[2];
        u = find(u); v = find(v);
        if (u == v) continue;
        par[v] = u;
        eds2.emplace_back((array<int, 3>) {w, u, v});
    }
    int cost[p + 1], val[p + 1][n + 1];
    for (int i = 1; i <= p; i++) {
        cin >> cost[i];
        for (int j = 1; j <= n; j++) cin >> val[i][j];
    }
    int ans = 1e18;
    for (int i = 0; i < (1 << p); i++) {
        vector<array<int, 3>> eds3 = eds2;
        int cur = 0;
        for (int j = 1; j <= p; j++) if ((i >> (j - 1)) & 1) {
            cur += cost[j];
            for (int k = 1; k <= n; k++) eds3.emplace_back((array<int, 3>) {val[j][k], k, n + j});
        }
        for (int i = 1; i <= n + p; i++) par[i] = i;
        sort(eds3.begin(), eds3.end());

        for (auto vec : eds3) {
            int w = vec[0], u = vec[1], v = vec[2];
            u = find(u); v = find(v);
            if (u == v) continue;
            par[v] = u;
            cur += w;
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}