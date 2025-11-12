#include <bits/stdc++.h>
#define int long long
using namespace std;
const int m = 998244353;
int n, a[5005], b[25], cnt, amx;
int mul(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            (res *= x) %= m;
        (x *= x) %= m;
        y >>= 1;
    }
    return res;
}
int C(int n, int k)
{
    k = min(k, n - k);
    if (!k)
        return 1;
    else if (k == 1)
        return n;
    int res = 1;
    for (int i = 0; i < k; i++)
        (res *= (n - i)) %= m, (res *= mul(i + 1, m - 2)) %= m;
    return res;
}
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), amx = max(amx, a[i]);
    if (n <= 20)
    {
        b[n] = 1;
        do
        {
            int sum = 0, mx = 0;
            for (int i = 1; i <= n; i++)
                if (b[i])
                    mx = max(mx, a[i]), sum += a[i];
            if (sum > mx * 2)
                cnt++, cnt %= m;
            for (int i = n; i >= 0; i--)
            {
                if (b[i])
                    b[i] = 0;
                else
                {
                    b[i] = 1;
                    break;
                }
            }
        }
        while (!b[0]);
    }
    else if (amx == 1)
    {
        for (int i = 3; i <= n; i++)
            (cnt += C(n, i)) %= m;
    }
    else
    {
        int s = 0, pre = 0, al = 0, predp = 0;
        for (int i = 1; i < n; i++)
            s += a[i];
        signed dp[s + 5];
        memset(dp, 0, sizeof dp); dp[0] = 1;
        sort(a + 1, a + n + 1);
        for (int i = 1; i < n; i++)
        {
            pre += a[i];
            for (int j = a[i] + 1; j <= a[i + 1]; j++)
                (predp += dp[j]) %= m;
            for (int j = pre; j >= a[i]; j--)
            {
                (dp[j] += dp[j - a[i]]) %= m, (al += dp[j - a[i]]) %= m;
                if (j <= a[i + 1])
                    (predp += dp[j - a[i]]) %= m;
            }
            (cnt += (al + m - predp)) %= m;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
