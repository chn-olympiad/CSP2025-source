#include <bits/stdc++.h>
using namespace std;
int n, m, seats[20][20], a[110], R, p = 1;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];

    R = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= m; i++)
    {
        if (p / n % 2 != 0)
        {
            for (int j = n; j > 0; j--)
            {
                seats[j][i] = a[p];
                p++;
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                seats[j][i] = a[p];
                p++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (seats[i][j] == R)
            {
                cout << j << ' ' << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
