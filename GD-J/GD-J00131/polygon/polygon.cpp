#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum[5005];
int ans = 0;
const int mod = 998244353;
void dfs(int cur, int s, int m)
{
    if (cur == 0)
    {
        if (s > m)
            ans = (ans + 1) % mod;
        return;
    }
    if (s + sum[cur] <= m)
        return;
    dfs(cur - 1, s, m);
    dfs(cur - 1, s + a[cur], m);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] == n)
    {
        ans = ((1ll * n * (n - 1) / 2) * (n - 2) / 3) % mod;
        printf("%d\n", ans);
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; i++)
        dfs(i - 1, a[i], a[i] * 2);
    printf("%d\n", ans);
    return 0;
}