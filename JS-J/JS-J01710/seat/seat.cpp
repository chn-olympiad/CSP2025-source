#include <bits/stdc++.h>
using namespace std;

int n, m, seat, g, x, y;
int a[500];
int mp[15][15];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            cin >> a[cnt];
            cnt++;
        }
    }
    g = a[1];
    sort(a + 1, a + cnt +1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        if (g == a[i])
        {
            x = (i-1) / n + 1;
            y = i % n;
            if (!y) y = n;
            if (x % 2 == 1)
            {
                break;
            }
            else
            {
                y = n - (y - 1);
                break;
            }
        }
    }
    cout << x << " " << y <<endl;
    return 0;
}
