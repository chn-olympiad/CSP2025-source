#include <bits/stdc++.h>
using namespace std;

int a[100020];
    int n, ans = 0;

void dfs(int dep, int sum, int last)
{
    if (dep == n + 1)
    {
        if (sum > 2 * last)
        {
            ans++;
        }
        return ;
    }
    dfs(dep + 1, sum + a[dep], a[dep]);
    dfs(dep + 1, sum, last);
}
int c(int n, int m)
{
    int f = 1;
    for (int i = n; i >= n - m + 1; i--)
    {
        f = f * i;
    }
    int  f2 = 1;
    for (int i = m; i >= 1; i--)
    {
        f2 = f2 * i;
    }
    return f / f2;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n] == 1)
    {
        int k = 0;
        for (int i = 3; i <= n; i++)
        {
            k += c(n, i);
        }
        cout << k % 998244353 << endl;
        return 0;
    }
    dfs(1, 0, 0);
    cout << ans % 998244353;
    return 0;
}
