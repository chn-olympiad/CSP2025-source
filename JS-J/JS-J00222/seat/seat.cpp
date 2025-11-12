#include <bits/stdc++.h>
using namespace std;

int a[109], b[12][12];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, mc;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    int k = a[1];
    sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; i++)
        if (k == a[i]) mc = n * m - i + 1;
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
                b[j][i] = (i - 1) * n + j;
        }
        else
        {
            for (int j = 1; j <= n; j++)
                b[j][i] = i * n + 1 - j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (b[i][j] == mc) cout << j << ' ' << i << endl;
    }
    return 0;
}
