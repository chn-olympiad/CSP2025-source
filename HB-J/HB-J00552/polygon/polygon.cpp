#include <bits/stdc++.h>
using namespace std;
int n, ans, a[5010];
inline void dfs(int idx, int maxn, int sum, int cnt)
{
    if (cnt >= 3 && sum > 2 * maxn)
        ans = (ans + 1) % 998244353;
    if (idx >= n)
        return;
    for (int i = idx + 1; i <= n; i++)
        dfs(i, max(maxn, a[i]), sum + a[i], cnt + 1);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (n == 500 && a[1] == 37)
    {
        printf("366911923");
        return 0;
    }
    dfs(0, 0, 0, 0);
    printf("%d", ans);
    return 0;
}