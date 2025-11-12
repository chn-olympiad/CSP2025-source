#include <bits/stdc++.h>
using namespace std;
int n, m, a[505], b[505], ans = 0;
string s;
const int mod = 998244353;
bool vis[505];
bool check()
{
    int cntg = 0, cnti = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0') cntg++;
        else if (cntg >= b[i]) cntg++;
        else cnti++;
    }
    if (cnti >= m) return 1;
    else return 0;
}
void dfs(int step)
{
    if (step > n)
    {
        if (check()) ans++;
        ans %= mod;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            b[step] = a[i];
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << ans % mod << endl;
    return 0;
}
