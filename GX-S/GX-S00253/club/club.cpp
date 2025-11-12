#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T;
int n;
int a[N][3];
int ans;

void dfs(int u, int x, int y, int z, int res)
{
    if (u > n)
    {
        ans = max(ans, res);
        return;
    }

    if (x < n / 2) dfs(u + 1, x + 1, y, z, res + a[u][0]);
    if (y < n / 2) dfs(u + 1, x, y + 1, z, res + a[u][1]);
    if (z < n / 2) dfs(u + 1, x, y, z + 1, res + a[u][2]);
}

void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j <= 2; j ++ )
        {
            cin >> a[i][j];
        }
    }

    dfs(1, 0, 0, 0, 0);

    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T -- ) solve();
    return 0;
}
