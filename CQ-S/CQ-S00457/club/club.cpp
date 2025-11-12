#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], dp[1005][1005], ans;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        for (int j = min(n, n / 2); j >= 0; j--)
            for (int k = min(n - j, n / 2); k >= 0; k--)
                dp[j][k] = 0;
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            for (int j = min(i, n / 2); j >= 0; j--)
                for (int k = min(i - j, n / 2); k >= 0; k--)
                    if (i - j - k <= n / 2)
                    {
                        if (j > 0)
                            dp[j][k] = max(dp[j - 1][k] + a[i][0], dp[j][k]);
                        if (k > 0)
                            dp[j][k] = max(dp[j][k - 1] + a[i][1], dp[j][k]);
                        if (j + k < i)
                            dp[j][k] = max(dp[j][k] + a[i][2], dp[j][k]);
                    }
        }
        for (int j = n / 2; j >= 0; j--)
            for (int k = min(n - j, n / 2); k >= 0; k--)
                ans = max(ans, dp[j][k]);
        cout << ans << '\n';
    }
    return 0;
}