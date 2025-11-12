#include <bits/stdc++.h>

using namespace std;
long long mod = 998244353;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    long long ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = m; i <= n; ++i)
    {
        long long ans1 = 1;
        for (int j = n; j >= n - i + 1; --j) ans1 = (ans1 * j) % mod;
       // cout << ans1 << " ";
        for (int j = 1; j <= i; ++j) ans1 = (ans1 / j) % mod;
        ans += ans1;
    }
    cout << ans << endl;
    return 0;
}
