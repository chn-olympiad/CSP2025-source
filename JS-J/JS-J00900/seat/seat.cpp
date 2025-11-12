#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n,m; cin >> n >> m;
    for (int i = 1; i <= n*m; i++)
        cin >> a[i];
    int ra = a[1];
    sort(a + 1, a + n*m + 1);
    for (int i = 1; i <= n*m; i++)
        if (a[n*m - i + 1] == ra)
        {
            int c, r;
            if (i > 1)
                c = (i-1) / n + 1;
            else c = 1;
            if (c % 2 == 0)
                r = n - ( (i-1) % n + 1) + 1;
            else r = (i-1) % n + 1;
            cout << c << ' ' << r << "\n";
            break;
        }
    return 0;
}
