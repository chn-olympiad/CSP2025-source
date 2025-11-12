#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int cnt = 0, n, m, c[510], a[510], l[510];
string s;
bool vis[510];
void dfs(int step, int num, int last)
{
    if (step > n)
    {
        if (num >= m)
        {
            cnt = (cnt + 1) % 998244353;
        }
        return;
    }
    if (n - step + 1 < m - num) return;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && last < c[i])
        {
            //cout << step << " " << i << endl;
            vis[i] = true;
            if (s[step - 1] == '1')
            {
                dfs(step + 1, num + 1, last);
                //cout << step << " " << s[step - 1] << endl;
            }
            else
            {
                dfs(step + 1, num, last + 1);
            }
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dfs(1, 0, 0);
    cout << cnt << endl;
    return 0;
}
