#include <bits/stdc++.h>
using namespace std;
int n, m, x, h, c, r, a[120];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++)
    {
        cin >> a[i];
    }
    x = a[1];
    sort(a, a + n * m + 1);
    for (int i = n * m; i >= 1; i --)
    {
        h ++;
        if (a[i] == x)
            break;
    }
    c = h / n;
    if (n * c < h)
        c ++;
    if (c % 2 == 1)
        r = n - (n * c - h);
    else
        r = n * c - h + 1;
    cout << c << ' ' << r;
    return 0;
}
