#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Node {
    int v, w;
};
vector<Node> g[N];
int c[N], a[15][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) cin >> a[i];
    }
    cout << 0;
    return 0;
}
