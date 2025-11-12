#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 15;
const int MAX_N = 1e4 + 5;
const int MAX_M = 1e6 + 5;

int n, M, k;
int u[MAX_M], v[MAX_M], m[MAX_M];
int c[MAX_N], a[MAX_K][MAX_N];

int ans;

int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    cin >> n >> M >> k;
    for (int i = 1; i <= M; i++) {
        cin >> u[i] >> v[i] >> m[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    sort (m + 1, m + M + 1);
    for (int i = 1; i <= n - 1; i++) {
        ans += m[i];
    }
    cout << ans << endl;
    //AC
    //rp++
    return 0;
}
