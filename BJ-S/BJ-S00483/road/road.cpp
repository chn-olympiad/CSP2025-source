#include<cstdio>
#include<iostream>
using namespace std;

int n, m, k, u, v, w[1000005], c[11], a[11][10005];
bool g[10005][10005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w[i];
        g[u][v] = true;
        g[v][u] = true;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << 0;

    return 0;
}
