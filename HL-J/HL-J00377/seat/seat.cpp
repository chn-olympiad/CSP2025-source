#include <bits/stdc++.h>
using namespace std;
int m, n, a[105], rg, ans;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    int mn = m * n;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    rg = a[1];
    sort(a + 1, a + mn + 1);
    for (int i = 1; i <= mn; i++)
    {
        if (a[i] == rg)
        {
            ans = mn - i + 1;
            break;
        }
    }
    if (ans % n == 0)
    {
        cout << ans / n << ' ';
        if ((ans / n) % 2 == 0)
            cout << 1;
        else
            cout << m;
    }
    else
    {
        cout << ans / n + 1 << ' ';
        if ((ans / n + 1) % 2 == 1)
            cout << ans % n;
        else
            cout << m + 1 - (ans % n);
    }
    return 0;
}
