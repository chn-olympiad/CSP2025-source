#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[15][15], a[105];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);
    int r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int flag = 1;
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        if (flag)
        {
            for (int j = 1; j <= n; j++)
                s[j][i] = a[cnt++];
        }
        else
        {
            for (int j = n; j >= 1; j--)
                s[j][i] = a[cnt++];
        }
        flag = flag ^ 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == r)
            {
                printf("%d %d", j, i);
                return 0;
            }
        }
    }
    return 0;
}