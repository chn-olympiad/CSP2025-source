#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 5, MR = 205;

int a[NR][5], b[NR], dp[MR][MR / 2][MR / 2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        bool flag1 = true, flag2 = true;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][2] != 0 || a[i][3] != 0) flag1 = false;
            if (a[i][3] != 0) flag2 = false;
        }

        if (flag1)
        {
            for (int i = 1; i <= n; i++) b[i] = a[i][1];
            sort(b + 1, b + n + 1);
            int ans = 0;
            for (int i = n; i >= n / 2 + 1; i--) ans += b[i];
            cout << ans << endl;
        }
        else if (flag2)
        {
            for (int i = 1; i <= n; i++) b[i] = a[i][1] - a[i][2];
            sort(b + 1, b + n + 1);
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                ans += a[i][2];
                if (i > n / 2) ans += b[i];
            }
            cout << ans << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                for (int j = 0; j <= min(i, n / 2); j++)
                    for (int k = 0; k <= min(i, n / 2); k++)
                    {
                        if (j + k > i || i - j - k > n / 2) continue;

                        dp[i][j][k] = 0;
                        if (j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                        if (k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                        if (i - j - k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                    }

            int ans = 0;
            for (int j = 1; j <= n / 2; j++)
                for (int k = 1; k <= n / 2; k++) ans = max(ans, dp[n][j][k]);
            cout << ans << endl;
        }
    }
    return 0;
}