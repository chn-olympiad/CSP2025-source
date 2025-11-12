#include <bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[5000];
void dfs(long long sum, long long cnt, long long i, long long maxn, long long last)
{
    if (cnt >= 3)
    {
        if (sum > 2 * maxn && cnt != last)
        {
            ans++;
            ans %= 998244353;
        }
    }
    if (i > n)
    {
        return;
    }
    dfs(sum + a[i], cnt + 1, i + 1, max(maxn, a[i]), cnt);
    dfs(sum, cnt, i + 1, maxn, cnt);
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
    if (n <= 20)
    {
        dfs(0, 0, 1, 0, -1);
    }
    else
    {
        for (int j = 3; j <= n; j++)
        {
            for (int i = n - j; i >= 0; i--)
            {
                if (i == 0)
                {
                    ans += 1;
                }
                else
                {
                    ans += i * j;
                }
                ans %= 998244353;
            }
        }

    }
    cout << ans;
    return 0;
}
