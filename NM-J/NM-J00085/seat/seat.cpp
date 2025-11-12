#include <bits/stdc++.h>
using namespace std;
constexpr int dir[][4] = {
    {0, -1},
    {0, 1},
};
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m + 1);
    int r;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort(a.begin() + 1, a.end(), greater<int>());
    if (n == 2 && m == 1)
    {
        if (r == a[1])
        {
            cout << 1 << ' ' << 1;
        }
        else
            cout << 2 << ' ' << 1;
        return 0;
    }
    int x = 1, y = 1;
    int d = 1;
    bool fl = 1;
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == r)
        {
            cout << x << ' ' << y;
            return 0;
        }
        if (y == n && i != 1 && fl)
        {
            d = 0;
            x++;
            fl = 0;
            continue;
        }
        if (y == 1 && i != 1 && fl)
        {
            d = 1;
            x++;
            fl = 0;
            continue;
        }
        x += dir[d][0];
        y += dir[d][1];
        fl = 1;
    }
    cout << x << ' ' << y;
}