#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

long long n, ans, a[5001], t[5001];
bool used[5001];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

bool check(int dep)
{
    long long tmp = 0, maxn = INT_MIN;
    for (int i = 1; i <= dep; i++)
    {
        if (t[i] > maxn)
        {
            maxn = max(maxn, t[i]);
        }
        tmp += t[i];
    }
    if (tmp > 2 * maxn)
    {
        return 1;
    }
    return 0;
}

void dfs(int dep, int cur, int lmt)
{
    if (cur > dep)
    {
        if (check(dep))
        {
            ans = (ans + 1) % MOD;
            return;
        }
        return;
    }
    for (int i = lmt; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            t[cur] = a[i];
            dfs(dep, cur + 1, i);
            used[i] = 0;
        }
    }
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 3; i <= n; i++)
    {
        dfs(i, 1, 1);
    }
    cout << ans;
    return 0;
}
