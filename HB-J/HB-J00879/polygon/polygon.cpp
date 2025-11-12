#include <bits/stdc++.h>
using namespace std;
int n, cnt;
vector<int> a;
vector<bool> vis;
void dfs(int k, int step, int mx, int sum, int bx)
{
    if (step == k)
    {
        if (sum > mx * 2)
        {
            cnt = (cnt + 1) % 998244353;
        }

        return;
    }
    for (int i = bx; i <= n; i++)
    {
        if (!vis[i])
        {
            bool flag = 0;
            int last;
            vis[i] = true;
            if (mx < a[i])
            {
                last = mx;
                mx = a[i];
                flag = 1;
            }
            sum += a[i];
            dfs(k, step + 1, mx, sum, i);
            sum -= a[i];
            if (flag == 1)
            {
                mx = last;
            }
            vis[i] = false;
        }
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    a.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 3; i <= n; ++i)
    {
        dfs(i, 0, INT_MIN, 0, 1);
    }
    cout << cnt;
    return 0;
}