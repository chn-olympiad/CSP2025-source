#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, u, x;
    cin >> n >> m;
    int a[n*m+5];
    for (int i = 1; i <= n*m; i++)
    {
        cin >> a[i];
    }
    x = a[1];
    int g[n*m+5];
    for (int j = 1; j <= n*m; j++)
    {
        bool bei = 1;
        for (int i = 1; i <= n*m; i++)
        {
            if (j % 2 == 1)
            {
                g[i] = 0;
            }
            g[i] = a[i];
            g[i+1] = a[i+1];
            if (a[i] < a[i+1])
            {
                int t;
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
        for (int i = 1; i <= n*m; i++)
        {
            if (a[i] != g[i])
            {
                bei = 0;
                break;
            }
        }
        if (bei = 1)
        {
            break;
        }
    }
    for (int i = 1; i <= n*m; i++)
    {
        if (a[i] == x)
        {
            u = i;
        }
    }
    int q;
    for (int i = 1; i <= m; i++)
    {
        if (u % n == 0)
        {
            q = u / n;
            cout << u / n << " ";
        }
        else
        {
            q = u / n + 1;
            cout << u / n + 1 << " ";
        }
        if (q % 2 == 0)
        {
            if (u % n == 0)
            {
                cout << 1;
            }
            else
            {
                cout << n - (u % n) + 1;
            }
        }
        else if (q % 2 == 1)
        {
            if (u % n == 0)
            {
                cout << n;
            }
            else
            {
                cout << u % n;
            }
        }
        break;
    }
    cout << endl;
    return 0;
}
