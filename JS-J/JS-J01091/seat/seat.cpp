#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[105];   //n hangshu, m lieshu

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    int q = a[1], f;

    sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; i++)
        if (a[i] == q)
        {
            f = n * m - i + 1;
            break;
        }

    int x, y;
    y = f % n;
    if (f % m == 0) x = f / m;
    else x = f / m + 1;
    if (y == 0) y = n;
    if (x % 2 == 0) y = n + 1 - y;
    cout << x << " " << y << "\n";
    return 0;
}
