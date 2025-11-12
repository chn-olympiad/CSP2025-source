#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, t;
int a[5005], ans;
int f[5005][5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], m = max(m, a[i]);
    sort(a + 1, a + n + 1);
    f[0][0] = 1;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j <= m + 1; ++j) {
        f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
        t = j + a[i + 1]; if(t > m) t = m + 1;
        f[i + 1][t] = (f[i + 1][t] + f[i][j]) % MOD;
    }
    for(int i = 3; i <= n; ++i)
        for(int j = a[i] + 1; j <= m + 1; ++j) ans = (ans + f[i - 1][j]) % MOD;
    cout << ans << '\n';
    return 0;
}
