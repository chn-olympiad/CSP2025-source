#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector <int> a[10010];
int w[10010][10010],c[20],ci[20][10010];


int main () {
    freopen("raol.in", "r", stdin);
    freopen("raol.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++ ) {
        int u,v;
        cin >> u >> v >> w[u][v];
        a[u].push_back(v);
        a[v].push_back(u);
        w[v][u] = w[u][v];
    }
    for(int i = 1; i <= k; i ++ ) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++) {
            cin >> ci[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++){

        }
    }
}
