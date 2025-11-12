#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 1, t;
    cin >> n;
    if (n - 1 >= 3) ans += n;
    for (int i = n - 2; i >= 3 && i > (n + 1) / 2; i--)
    {
        t = n;
        for (int j = n - 1; j > i; j--)
            t = ((t % 998244353) * j / (n - j + 1)) % 998244353;
        ans = (ans + (t * 2) % 998244353) % 998244353;
    }
    if (n % 2 && (n + 1) / 2 >= 3)
    {
        t = n;
        for (int j = n - 1; j > (n + 1) / 2; j--)
            t = ((t % 998244353) * (j % 998244353) / (n - j + 1)) % 998244353;
        ans = (ans + t % 998244353) % 998244353;
    }
    cout << ans % 998244353 << '\n';
    return 0;
}