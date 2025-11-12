#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int t, n;
int a[N][4];

int dfs(int step, int c1, int c2, int c3, int sum)
{
    if (c1 > n / 2 || c2 > n / 2 || c3 > n / 2)
    {
        return -1;
    }
    if (step == n + 1)
    {
        return sum;
    }
    int r1 = dfs(step + 1, c1 + 1, c2, c3, sum + a[step][1]);
    int r2 = dfs(step + 1, c1, c2 + 1, c3, sum + a[step][2]);
    int r3 = dfs(step + 1, c1, c2, c3 + 1, sum + a[step][3]);
    return max(r1, max(r2, r3));
}

void ac()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = max(a[i][1], max(a[i][2], a[i][3]));
        res += t;
    }
    printf("%d\n", res);
}

void normal()
{
    if (n > 10)
    {
        ac();
        return;
    }
    int ans = dfs(1, 0, 0, 0, 0);
    printf("%d\n", ans);
}

int temp[N];

bool cmp(int x, int y)
{
    return x > y;
}

void spec1()
{
    for (int i = 1; i <= n; i++)
    {
        temp[i] = a[i][1];
    }
    sort(temp + 1, temp + n + 1, cmp);
    int res = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        res += temp[i];
    }
    printf("%d\n", res);
}

void solve()
{
    bool flag1 = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][2] || a[i][3])
        {
            flag1 = false;
            break;
        }
    }
    if (flag1)
    {
        spec1();
    }
    else
    {
        normal();
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        solve();
    }
    return 0;
}