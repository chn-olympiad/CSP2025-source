#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int cnt = 0, n, a[100010][5], maxn = -1;
bool vis[510];
void dfs(int step, int ca, int cb, int cc, int sum)
{
    //cout << n << " " << step << endl;
    if (step > n)
    {
        maxn = max(maxn, sum);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            //cout << ca << " " << cb << " " << cc << " " << sum << endl;
            if (ca <= n / 2)
            {
                dfs(step + 1, ca + 1, cb, cc, sum + a[i][1]);
            }
            if (cb <= n / 2)
            {
                dfs(step + 1, ca, cb + 1, cc, sum + a[i][2]);
            }
            if (cc <= n / 2)
            {
                dfs(step + 1, ca, cb, cc + 1, sum + a[i][3]);
            }
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        maxn = -1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(1, 0, 0, 0, 0);
        cout << maxn << endl;
    }
    return 0;
}
