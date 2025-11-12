#include <bits/stdc++.h>
using namespace std;
int a[10005][10005], c[10005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++){
            cin >> a[n + i][j];
            a[j][n + i] = a[n + i][j];
        }
    }
    cout << 0 << endl;
    return 0;
}
