#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MOD = 998244353;
int n, m, a[MAXN], c[MAXN];
int ans = 0;
int t[MAXN];
bool b[MAXN];
bool check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            cnt++;
        else if (cnt >= c[t[i]])
                cnt++;
    }
    if (n - cnt >= m)
        return true;
    return false;
}
void dfs(int x)
{
    if (x == n + 1)
    {
        if (check())
        {
            ans++;
            ans %= MOD;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!b[i])
        {
            b[i] = true;
            t[x] = i;
            dfs(x + 1);
            t[x] = 0;
            b[i] = false;
        }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        a[i] = tmp - '0';
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << ans << '\n';
    return 0;
}
