#include <bits/stdc++.h>
using namespace std;

int n, m, sb, rq[15][15], a[105];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
    {
        scanf ("%d", &a[i]);
    }
    sb = a[1];
    sort (a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j % 2 == 1) rq[i][j] = a[i + (j / 2) * 2 * n];
            else rq[i][j] = a[j * n - i + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sb == rq[i][j])
            {
                cout << j << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}
