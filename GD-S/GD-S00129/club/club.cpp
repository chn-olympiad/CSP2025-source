#include <bits/stdc++.h>
using namespace std;
int t, n;
const int N = 205;
const int M = 1e5 + 5;
int a[M][4], dp[N][N][N], b[M];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool teshuA = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if (a[i][2] != 0 || a[i][3] != 0)
                teshuA = 0;
        }
        if (teshuA)
        {
            for (int i = 1; i <= n; i++)
                b[i] = a[i][1];
            sort(b + 1, b + n + 1, cmp);
            int sum = 0;
            for (int i = 1; i <= n / 2; i++)
                sum += b[i];
            printf("%d\n", sum);
        }
        else
        {
            memset(dp, 0, sizeof(dp));
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int x = 0; x <= i && x <= n / 2; x++)
                {
                    for (int y = 0; y <= i && y <= n / 2; y++)
                    {
                        int z = i - x - y;
                        if (z > n / 2 || z < 0)
                            continue;
                        if (x <= n / 2 && x != 0)
                            dp[x][y][z] = max(dp[x][y][z], dp[x - 1][y][z] + a[i][1]);
                        if (y <= n / 2 && y != 0)
                            dp[x][y][z] = max(dp[x][y][z], dp[x][y - 1][z] + a[i][2]);
                        if (z <= n / 2 && z != 0)
                            dp[x][y][z] = max(dp[x][y][z], dp[x][y][z - 1] + a[i][3]);
                        ans = max(ans, dp[x][y][z]);
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}