#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005][5], dp[205][205][205];
int b[100005];

void solve()
{
    int n, task = 0;
    bool az2 = true, az3 = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if (a[i][2] != 0)
            az2 = false;
        if (a[i][3] != 0)
            az3 = false;
    }
    if (n <= 200)
        task = 1;
    else if (az2 && az3)
        task = 2;
    else if (az3)
        task = 3;
    else // for random data
        task = 4;
    if (task == 1)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++)
                    dp[i][j][k] = 0;
        dp[1][0][0] = a[1][1];
        dp[0][1][0] = a[1][2];
        dp[0][0][1] = a[1][3];
        for (int m = 2; m <= n; m++)
        {
            for (int i = 0; i <= m; i++)
            {
                for (int j = 0; i + j <= m; j++)
                {
                    int k = m - i - j;
                    if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[m][1]);
                    if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[m][2]);
                    if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[m][3]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i * 2 <= n; i++)
        {
            for (int j = 0; j * 2 <= n; j++)
            {
                int k = n - i - j;
                if (k * 2 > n)
                    continue;
                ans = max(ans, dp[i][j][k]);
            }
        }
        cout << ans << endl;
    }
    else if (task == 2)
    {
        for (int i = 1; i <= n; i++)
            b[i] = a[i][1];
        sort(b + 1, b + 1 + n, greater<int>());
        int ans = 0;
        for (int i = 1; i * 2 <= n; i++)
            ans += b[i];
        cout << ans << endl;
    }
    else if (task == 3)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += max({a[i][1], a[i][2], a[i][3]});
        cout << ans << endl;
    }
    else if (task == 4)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += max({a[i][1], a[i][2], a[i][3]});
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

/*
键盘好难用啊喵。
第一题看起来很像 DP 呢喵。

先冲 55 分喵。
设 dp[i][j][k] 表示三个部门分别有 i, j, k 人的满意度之和的最大值。
显然有：
dp[i][j][k] = max(
    dp[i - 1][j][k] + a[i][1],
    dp[i][j - 1][k] + a[i][2],
    dp[i][j][k - 1] + a[i][3]
    )
看起来很对啊喵。
30min 搞定喵。

接下来冲特殊性质喵。
先搞 A 喵。
显然贪心地让一半的人选部门一，剩下的喝西北风。
5min 搞定喵，60 分到手。

性质 B 就复杂起来了喵。
肯定是一半选一、一半选二。
但是怎么选呢喵。肯定不能是贪心了，见样例一的第三个测试数据。

有点复杂喵，先做性质 C。
因为纯随机，所以如果贪心选，部门人数的期望最大值应该是 n/3，似乎没有问题喵。
10min 搞定喵，70 分到手。
只剩 2h 了，看看别的题喵。
*/