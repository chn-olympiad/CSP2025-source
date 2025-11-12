#include <bits/stdc++.h>
using namespace std;

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, a, cnt = 1;
    cin >> n >> m >> a;
    for (int i = 2; i <= n * m; i++)
    {
        int x;
        cin >> x;
        if (x > a) cnt++;
    } 
    int t = 0;
    for (int i = 1, j = 1, d = 1;; i += d)
    {
        if (i == n + 1) i = n, j++, d *= -1;
        if (i == 0) i = 1, j++, d *= -1;
        t++;
        if (t == cnt)
        {
            cout << j << " " << i << "\n";
            return 0;
        } 
    } 
    return 0;
} 