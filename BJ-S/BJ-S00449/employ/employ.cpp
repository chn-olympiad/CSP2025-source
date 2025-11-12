#include <bits/stdc++.h>
using namespace std;

const int NR = 505, Mod = 998244353;

int n, m, len, ans = 0, c[NR];
string s;

bool vis[NR];

void dfs(int x, int pass)
{
    if (x == n + 1)
    {
        if (pass >= m) ans = (ans + 1) % Mod;
        return ;
    }
    if (pass + (n - x + 1) < m) return ;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (s[x] == '0' || (x - pass - 1) >= c[i]) dfs(x + 1, pass);
            else dfs(x + 1, pass + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("employ.in", 'r', stdin);
    freopen("employ.out", 'w', stdout);
    
    cin >> n >> m >> s;
    len = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    if (n <= 18)
    {
        dfs(1, 0);
        cout << ans << endl;
    }
    else cout << 0 << endl;
    return 0;
}