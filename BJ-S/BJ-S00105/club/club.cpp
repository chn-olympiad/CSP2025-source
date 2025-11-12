#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100005;
int a[N], b[N], c[N], dp[205][205][205][3];
bool ans[N];

struct node
{
    int id, cnt;
}d[N];

bool cmp(node x, node y)
{
    return x.cnt > y.cnt;
}

int main()
{
    freopen("clue.in", "r", stdin);
    freopen("clue.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, sizeof(dp), 0);
        memset(ans, sizeof(ans), 0);
        int n;
        cin >> n;
        bool flag_b = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (c[i] != 0) flag_b = 0;
        }
        if (flag_b)
        {
            for (int i = 1; i <= n; i++)
            {
                d[i].cnt = a[i] - b[i];
                d[i].id = i;
            }
            sort(d + 1, d + n + 1, cmp);
            for (int i = 1; i <= n / 2; i++)
            {
                ans[d[i].id] = 1;
            }
            int ans1 = 0;
            for (int i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
                if (ans[i]) ans1 += a[i];
                else ans1 += b[i];
            }
            cout << ans1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (j > n / 2 || k > n / 2 || (i - j - k) > n / 2 || (i - j - k) < 0) continue;
                    if (j != 0) dp[i][j][k][0] = max(dp[i - 1][j - 1][k][0], max(dp[i - 1][j - 1][k][1], dp[i - 1][j - 1][k][2])) + a[i];
                    if (k != 0) dp[i][j][k][1] = max(dp[i - 1][j][k - 1][0], max(dp[i - 1][j][k - 1][1], dp[i - 1][j][k - 1][2])) + b[i];
                    if (i != j + k) dp[i][j][k][2] = max(dp[i - 1][j][k][0], max(dp[i - 1][j][k][1], dp[i - 1][j][k][2])) + c[i];
                }
            }
        }
        int ans2 = -2e9;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i > n / 2 || j > n / 2 || (n - i - j) > n / 2) continue;
                ans2 = max(max(ans2, dp[n][i][j][0]), max(dp[n][i][j][1], dp[n][i][j][2]));
            }
        }
        cout << ans2 << endl;
    }
    return 0;
}
