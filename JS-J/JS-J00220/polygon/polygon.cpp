#include<bits/stdc++.h>
using namespace std;
long long n, a[5100], m, ans[5100];
bool vis[5100];
int maxn = 0, sum = 0;
int cnt, jsq;
void dfs(int dep)
{
    if (dep > n)
    {
        for (int i = 1; i <= dep; i++)
        {
            if (maxn < ans[i])
                maxn = ans[i];
            sum += ans[i];
        }
        return;
    }
    for (int i = 1; i <= 3 + dep; i++)
    {
        if (vis[i] == 0)
        {
            ans[i] = a[dep];
            vis[i] = 1;
            dfs(dep + 1);
            vis[i] = 0;
        }
    }
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
    if (n < 3)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= cnt; i++)
    {
        dfs(1);
        if (sum > maxn * 2)
            jsq++;
    }
    cout << jsq % 998244353;

    return 0;
}
