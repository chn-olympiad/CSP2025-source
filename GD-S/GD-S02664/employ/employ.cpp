#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 110, mod = 998244353;
int n, m, ds, f[2][N][N][N], pos[N], c[N];
string s;
void add(int &x, int y) {
    x = (x + y) % mod;
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    IOS;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    memset(pos, -1, sizeof pos);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            pos[++ds] = i;
    pos[++ds] = n;
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= ds; i++)
        f[0][i][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int now = i & 1, lst = now ^ 1;
        memset(f[now], 0, sizeof f[now]);
        for (int j = 1; j <= ds; j++)
            for (int k = 1; k <= pos[j]; k++) {
                for (int p = 0; p <= min(i, k); p++) {
                    if (j <= c[i + 1] and p)
                        add(f[now][j][k][p], f[lst][j][k - 1][p - 1] * (pos[j] - k) % mod);
                    add(f[now][j][k][p], f[lst][j][k - 1][p] * (pos[j] - k) % mod);
                }
            }
    }
    int ans = 0;
    for (int i = m; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= ds; k++)
                add(ans, f[n & 1][k][j][i]);
    cout << ans;
    return 0;
}
