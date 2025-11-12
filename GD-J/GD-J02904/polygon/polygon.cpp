#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long n;
const long long p = 998244353;
//sub_ai_is_one
    long long quick_power(long long x, long long y)
    {
        // cout << x << " " << y << "\n";
        if (y == 1) return x;
        if (y == 0) return 1;
        long long num = quick_power(x, y / 2);
        if (y & 1) return num * num % p * x % p;
        return num * num % p;
    }
    long long inv(long long x)
    {
        return quick_power(x, p - 2);
    }
    long long f[5005];
    long long inf[5005];
    void init()
    {
        f[0] = inf[0] = 1;
        for (long long i = 1; i <= 5000; i ++)
        {
            f[i] = f[i - 1] * i % p;
            inf[i] = inf[i - 1] * inv(i) % p;
        }
    }
    long long c(long long n, long long m)
    {
        // cout << f[n] << " " << f[m + 1] << " " << f[m] << "\n";
        return f[n] * inf[n - m] % p * inf[m] % p;
    }
void sub_ai_is_one()
{
    init();
    long long ans = 0;
    for (long long i = 3; i <= n; i ++)
    {
        ans = (ans + c(n, i)) % p;
    }
    cout << ans;
    return;
}
//sub_smalln
    long long ans = 0;
    bool vis[25];
    void dfs(long long step)
    {
        if (step > n)
        {
            long long last = 0;
            long long sum = 0;
            for (long long i = 1; i <= n; i ++)
            {
                if (vis[i])
                {
                    last = i;
                    sum += a[i];
                }
            }
            if (a[last] * 2 < sum)
            {
                ans ++;
            }
            return;
        }
        vis[step] = 1;
        dfs(step + 1);
        vis[step] = 0;
        dfs(step + 1);
        return;
    }
void sub_smalln()
{
    sort(a + 1,a + n + 1);
    dfs(1);
    cout << ans;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool F = 1;
    for (long long i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (a[i] != 1) F = 0;
    }
    if (F)
    {
        sub_ai_is_one();
    }
    else
    {
        sub_smalln();
    }
    return 0;
}