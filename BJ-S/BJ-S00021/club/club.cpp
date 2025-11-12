#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using pii = pair<int, int>;
const int N = 200 + 5;

int n, a[N], b[N], c[N], f[N][N][N];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                f[i][j][k] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, n / 2); j++) {
            for (int k = 0; k <= min(i - j, n / 2); k++) {
                int l = i - j - k;
                if (l > n / 2) continue;

                if (j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i]);
                if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + b[i]);
                if (l) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + c[i]);
                ans = max(ans, f[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) sol();

    return 0;
}
