#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    int n, m, a[205], b[15][15], c = 0;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n * m; i++)
    {
        if(a[i + 1] > a[i])
        {
            sort (a[i], a[i + 1]);
        }
    }
    c = a[1];
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            a[j] = b[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] == c)
            {
                cout << i << j;
            }
        }
    }
    return 0;
}
