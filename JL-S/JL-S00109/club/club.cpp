#include <bits/stdc++.h>
using namespace std;
const int o = 1e5 + 5;
int t, n, g, f[o][4];

void dfs(int k, int a, int b, int c, int ans)
{
    if (k > n)
    {
        g = max(g, ans);
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        if (a < n / 2) dfs(k + 1, a + 1, b, c, ans + f[k][1]);
        if (b < n / 2) dfs(k + 1, a, b + 1, c, ans + f[k][2]);
        if (c < n / 2) dfs(k + 1, a, b, c + 1, ans + f[k][3]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        g = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> f[i][1] >> f[i][2] >> f[i][3];
        if (n <= 30) dfs(1, 0, 0, 0, 0);
        else
        {
            bool p = 0;
            for (int i = 1; i <= n; i++) if (f[i][2] != 0 || f[i][3] != 0) {p = 1; break;}
            if (p) for (int i = 1; i <= n; i++) g += max(f[i][1], max(f[i][2], f[i][3]));
            else
            {
                int ss[n + 1];
                for (int i = 1; i <= n; i++) ss[i] = f[i][1];
                sort(ss + 1, ss + n + 1);
                for (int i = n; i > n / 2; n--) g += ss[i];
            }
        }
        cout << g << "\n";
    }
    return 0;
}
