#include <bits/stdc++.h>
using namespace std;
int a[105], b[15][15];
bool cmp(int x, int y)
{
    return x < y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, pos;
    cin >> n >> m;
    cin >> pos;
    a[1] = pos;
    for (int i = 2;i <= n * m;i++)
        cin >> a[i];
    sort(a + 1, a + n * m + 1, cmp);
    for (int j = 1;j <= m;j++)
    {
        if (j % 2 == 1)
        {
            for (int i = 1;i <= n;i++)
                b[i][j] = a[(j - 1) * n + i];
        }
        if (j % 2 == 0)
        {
            for (int i = n;i >= 1;i--)
                b[i][j] = a[j * n - i + 1];
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (b[i][j] == pos)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    return 0;
}





