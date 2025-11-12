#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int calc(int a1, int b)
{
    if (a1 == 1)
    {
        return b;
    }
    if (a1 == b)
    {
        return 1;
    }
    if (a1 == 0)
    {
        return 0;
    }
    int x = 1, y = 1;
    int tmp = a1;
    for (int i = 1; i <= tmp; i++)
    {
        x *= a1--;
        y *= b--;
    }
    return (int)(y / x);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 3)
    {
        int mx = max(max(a[1], a[2]), a[3]);
        int sum = a[1] + a[2] + a[3];
        if (mx * 2 < sum)
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        ans += calc(i, n);
    }
    cout << ans << endl;
    return 0;
}
