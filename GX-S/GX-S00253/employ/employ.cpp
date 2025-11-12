#include <bits/stdc++.h>

using namespace std;

const int N = 510, MOD = 998244353;

int n, m;
int c[N];
char s[N];
int ans;
bool st[N];

void dfs(int u, int res)
{
//    cout << u << ' ' << res << ' ';
//    for (int i = 1; i <= n; i ++ ) cout << st[i] << ' ';
//    cout << '\n';
    if (u > n)
    {
        if (res >= m) ans = (ans + 1) % MOD;
//        cout << '\n'
        return;
    }

    for (int i =  1; i <= n; i ++ )
        if (!st[i])
        {
            st[i] = 1;
            if (u - res - 1 >= c[i]) dfs(u + 1, res);
            else if (s[u] == '1') dfs(u + 1, res + 1);
            else dfs(u + 1, res);
            st[i] = 0;
        }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s + 1;
    for (int i = 1; i <= n; i ++ ) cin >> c[i];

        memset(st, 0, sizeof st);
        dfs(1, 0);
    cout << ans;
    return 0;
}
