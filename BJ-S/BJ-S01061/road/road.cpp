#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, m, k, u, v, w, g[N][N];
int c[20], a[20][N], prc[N][N];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int l = 1; l <= k; l++){
                prc[i][j] = min(g[i][j], c[l] + a[l][i] + a[l][j]);
            }
            ans += prc[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}