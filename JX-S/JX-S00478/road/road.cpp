#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
const int N = 1e4 + 5;
const int K = 10;
int u[M], v[M], w[M];
int c[K];
int a[K][N];
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w",stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j= 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    return 0;
}
