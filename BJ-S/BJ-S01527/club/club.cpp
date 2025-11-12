#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, a[100005], b[100005], c[100005], f[205][205][205], ans, s1, s2, t[100005];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = s1 = s2 = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
        for (int i = 1; i <= n; ++i)
        {
            s1 += b[i];
            s2 += c[i];
        }
        if (s1 == 0)
        {
            sort(a + 1, a + n + 1);
            for (int i = n / 2 + 1; i <= n; ++i) ans += a[i];
            cout << ans << '\n';
            continue;
        }
        if (s2 == 0)
        {
            for (int i = 1; i <= n; ++i) t[i] = a[i] - b[i];
            sort(t + 1, t + n + 1);
            for (int i = 1; i <= n / 2; ++i) ans -= t[i];
            for (int i = 1; i <= n; ++i) ans += a[i];
            cout << ans << '\n';
            continue;
        }
        if (n > 200)
        {
            int ans = 0;
            for (int i = 1; i <= n; ++i) ans += max(a[i], max(b[i], c[i]));
            cout << ans << '\n';
            continue;
        }
        memset(f, -0x3f, sizeof f);
        f[0][0][0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= i; ++j)
                for (int k = 0; k <= i - j; ++k)
                {
                    f[i][j][k] = f[i-1][j][k] + c[i];
                    if (j) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i]);
                    if (k) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + b[i]);
                }
        for (int i = 0; i <= n / 2; ++i)
            for (int j = 0; j <= n / 2; ++j)
                if (i + j >= n / 2)
                    ans = max(ans, f[n][i][j]);
        cout << ans << '\n';
    }
    return 0;
}
