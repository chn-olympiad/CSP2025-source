#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[105], x;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n * m; i++)
    {
        cin >> a[i];
        if (i == 1) x = a[i];
    }
    sort(a + 1, a + n * m + 1);
    int id = n * m;
    for (ll i = 1; i <= m; i++)
    {
        if (i % 2)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (a[id] == x)
                {
                    cout << i << ' ' << j << '\n';
                }
                id--;
            }
        }
        else
        {
            for (ll j = n; j >= 1; j--)
            {
                if (a[id] == x)
                {
                    cout << i << ' ' << j << '\n';
                }
                id--;
            }
        }
    }
    return 0;
}
