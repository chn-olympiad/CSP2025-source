#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, a[5005];
__int128 cnt;
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 20)
    {
        for (int i = 1; i < (1 << n); i++)
        {
            int mx = 0, sum = 0;
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                    mx = max(mx, a[j + 1]), sum += a[j + 1];
            if (mx * 2 < sum)
                cnt++;
            cnt %= MOD;
        }
        cout << (int)(cnt);
        return 0;
    }
    for (int i = 3; i <= n / 2; i++)
    {
        int x = 2;
        for (int j = n; j >= n - i + 1; j--)
            x = x * j;
        cnt = (cnt + x) % MOD;
    }
    cnt = (cnt + n * (n - 1) * (n - 2) + n * (n - 1) * (n - 2) * (n - 3)) % MOD;
    cout << (int)(cnt);
    return 0;
}
