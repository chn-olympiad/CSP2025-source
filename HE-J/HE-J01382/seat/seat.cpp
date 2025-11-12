#include <bits/stdc++.h>
using namespace std;
int n, m, a[107];
int r;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort (a + 1, a + n * m + 1, cmp);
    int k = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[++k] == r)
            {
                cout << i << " ";
                if (i % 2 == 0)
                {
                    cout << n - j + 1;
                }
                else
                {
                    cout << j;
                }
            }
        }
    }
    return 0;
}
