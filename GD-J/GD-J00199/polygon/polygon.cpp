#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 5e3 + 10;
const int MOD = 998244353;

int qpow(int a, int b = MOD - 2)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n, a[N], f[2][N], ans;

signed main()
{
    if (1)
    {
        freopen("polygon.in", "r", stdin);
        freopen("polygon.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    f[0][0] = 1;
    for (int i = 1, cur = 1, pre = 0; i <= n; ++i, swap(cur, pre))
    {
        int sum = 0;
        for (int j = 0; j <= a[i]; ++j)
        {
            (sum += f[pre][j]) %= MOD;
        }
        (ans += sum) %= MOD;
        for (int j = 0; j <= 5000; ++j)
        {
            if (j >= a[i])
            {
                f[cur][j] = (f[pre][j] + f[pre][j - a[i]]) % MOD;
            }
            else
            {
                f[cur][j] = f[pre][j];
            }
        }
    }
    ans = (qpow(2, n) - ans + MOD - 1 + MOD) % MOD;
    cout << ans << '\n';
}