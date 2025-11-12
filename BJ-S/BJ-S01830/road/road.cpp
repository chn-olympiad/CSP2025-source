#include <bits/stdc++.h>
using namespace std;
const int kMax = 100005;
int n, m, k;
int u[kMax], v[kMax], w[kMax];
int c[kMax];
int a[kMax][kMax];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
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
    if(k == 0) {
        for (int i = 1; i <= m; i++) {
            ans += w[i];
        }
    }
    return 0;
}

