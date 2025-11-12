#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], d, r;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    r = a[1];
    sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; i++)
        if (r == a[i])
        {
            d = n * m - i + 1;
            break;
        }
    int x = ceil(d * 1.0 / n);
    cout << x << " ";
    if (x & 1)
        cout << d - (x - 1) * n;
    else
        cout << n - (d - (x - 1) * n) + 1;
    return 0;
}
