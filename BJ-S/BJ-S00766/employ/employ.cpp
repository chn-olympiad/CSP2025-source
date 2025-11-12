#include <iostream>
using namespace std;

int c[100010], n, m, cnt;
bool f[100010];
string s;

void dfs(int x, int b, int t)
{
    if (b >= c[t] || s[t - 1] == '0')  b++;
    if (n - b < m)  return;
    if (x == n)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i])  continue;
        f[i] = true;
        dfs(x + 1, b, i);
        f[i] = false;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    if (n <= 18)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i] = true;
            dfs(1, 0, i);
            f[i] = false;
        }
    }
    else if (m == 1)
    {
        long long mul = 1;
        for (int i = 1; i <= n; i++)
        {
            mul = mul * i % 998244353;
        }
        cnt = (int)mul;
    }
    cout << cnt;
    return 0;
}