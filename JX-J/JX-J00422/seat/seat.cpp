#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct node
{
    int mark;
    bool isR = 0;
} a[101];

struct Point
{
    int x, y;
} ans;

bool cmp(node a, node b)
{
    return a.mark > b.mark;
}

Point solve()
{
    int d = 1;
    for (int i = 0; i < m; i++)//lie
    {
        d = 1 - d;
        if (d == 0)
        {
            for (int j = 0; j < n; j++)//hang
            {
                if (a[cnt++].isR)
                {
                    return {i, j};
                }
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {

                if (a[cnt++].isR)
                {
                    return {i, j};
                }
            }
        }
    }
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = read(), m = read();
    for (int i = 0; i < n * m; i++)
    {
        a[i].mark = read();
    }
    a[0].isR = 1;
    sort(a, a + n * m - 1, cmp);
    ans = solve();
    printf("%d %d", ans.x + 1, ans.y + 1);
    return 0;
}
