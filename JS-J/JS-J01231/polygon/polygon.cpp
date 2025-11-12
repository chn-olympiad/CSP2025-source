#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 5000, M = 998244353;
int n, a[N + 5];

int k[N + 5];

int sum (int m)
{
    int ans = 1;
    for (int i = 1;i <= m;i++)
    {
        ans = ans * (n - i + 1);
        ans %= M;
    }
    int t = 1;
    for (int i = 1;i <= n;i++)
    {
        t *= 1;
        t %= M;
    }
    return ans / t;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n == 3)
    {
        sort (a + 1, a + n + 1);
        if (a[1] + a[2] > 2 * a[3])
        {
            cout << 1 << '\n';
            return 0;
        }
        cout << 0 << '\n';
        return 0;
    }
    int ans = n + n * (n - 1) / 2;
    if (n % 2 == 0)
    {
        ans += sum(n / 2);
        n -= 1;
    }
    for (int i = 3; i <= n / 2;i++)
    {
        ans += (sum(i) * 2);
        ans %= M;
    }

    cout << ans << '\n';
    return 0;
}
