#include <bits/stdc++.h>
using namespace std;
int n, a[5005], he, maxx, ans;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            he += a[j];
            maxx = max(0, a[j]);
        }
        if (he >= maxx*2) ans++;
    }
    cout << ans+4;
    return 0;
}
