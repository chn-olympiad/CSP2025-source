#include <bits/stdc++.h>

using namespace std;
#define int long long
int ans, a[5010], n, cnt, mod = 998244353;
void dfs(int id, int maxn, int len, int sum)
{
    if (id > n) return;
    int maxn1 = max(maxn, a[id]);
    if (len + 1 >= 3 && sum + a[id] > maxn1 * 2) ans = (ans + 1) % mod;
    dfs(id + 1, maxn1, len + 1, sum + a[id]);
    dfs(id + 1, maxn, len, sum);
}
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1) ++cnt;
    }
    if (cnt == n)
    {
        long long ans = 0;
        for (int i = 3; i <= n; ++i)
        {
            long long ans1 = 1;
            for (int j = n; j >= n - i + 1; --j) ans1 *= j;
            for (int j = 2; j <= i; ++j) ans1 /= j;
            ans = (ans + ans1) % mod;
        }
        cout << ans << endl;
        return 0;
    }
    dfs(1, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
