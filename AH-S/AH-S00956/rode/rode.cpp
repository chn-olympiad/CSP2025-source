#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int dist[N][N], n, m, k;
int main() {
    freopen ("rode.in", "r", stdin);
    freopen ("rode.out", "w", stdout);
    memset(dist, 0x3f3f3f3f, sizeof dist);
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }
    for (int k = 1; k <= n; i++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}
