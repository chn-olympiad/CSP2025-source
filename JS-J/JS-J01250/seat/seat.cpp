#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, m, a[105], c = 1, r = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    LL x = n * m;
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
    }
    sort(a + 2, a + x + 1);
    for (int i = x; i > 1; i--)
    {
        if (a[i] < a[1])
        {
            cout << c << " " << r;
            return 0;
        }
        if ((r + 1 > m && c % 2 == 1) || (r - 1 == 0 && c % 2 == 0))
        {
            c++;
        }
        else
        {
            if (c % 2 == 1) r++;
            else r--;
        }
    }
    cout << c << " " << r;
    return 0;
}
