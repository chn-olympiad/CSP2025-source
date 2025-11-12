#include <bits/stdc++.h>

using namespace std;

int a[10005][20], c[20], u[100005], v[100005], w[100005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    long long ans;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        ans+=w[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        ans += c[i];
        for (int j = 1; j <= n+1; j++) {
            cin >> a[i][j];
            ans += a[i][j];
        }
    }
    cout << ans;
    return 0;
}
