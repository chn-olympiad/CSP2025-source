#include <bits/stdc++.h>
using namespace std;

int ans, n, a[10005];

void dfs(int step, int sum, int maxn, int cnt)
{
    if (step > n)
    {
        if (maxn * 2 < sum && cnt >= 3) ans++;
        return;
    }
    dfs(step + 1, sum, maxn, cnt);
    dfs(step + 1, sum + a[step], a[step], cnt + 1);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    dfs(1, 0, 0, 0);
    cout << ans;
    return 0;
}
