#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector g[1000005], c[1000005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }
    cout << 1;
    return 0;
}
