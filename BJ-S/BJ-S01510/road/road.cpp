#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e4 + 10;

int n, m, k;
int u[N], v[N], w[N];
int c[N], a[5][M];
int t[N], he;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        t[u[i]] = v[i];
        t[v[i]] = u[i];
        he += u[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            he += a[i][j];
        }
    }
    cout << he << "\n";
    return 0;
}
