#include <bits/stdc++.h>
#define int long long
using namespace std;

bool a[20005];

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x, ans = 0;
    cin >> n >> k;
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x == 1) ans++;
        }
        cout << ans << '\n';
    }
    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (!a[i]) ans++;
            if (a[i] && a[i - 1]) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}