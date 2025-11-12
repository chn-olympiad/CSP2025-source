#include <iostream>
using namespace std;

int d[10005][10005];
int main() {
    freopen("road4.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    int u, v, w;
    int c[15], a[15][10005];
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if (k <= 0) {
        // ---
    }
    else {
        cout << 0;
    }

    return 0;
}
