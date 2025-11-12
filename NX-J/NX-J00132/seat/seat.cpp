#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[];
    int c = 0, r = 0;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            c = 1;
            for (int j = 1; j <= n; j++)
            {
                if (a[0] > a[j] && a[0] < a[n])
                {
                    r = a[0];
                }
                else
                {
                    r = a[j];
                }
            }
        }
        else
        {
            r = 1;
            c = m;
        }
    }
    cout << c << " " << r;
    return 0;
}
