#include <bits/stdc++.h>
using namespace std;

int fread()
{
    int r = 0;
    char ch;
    ch = getchar();
    while ('0' <= ch && ch <= '9')
    {
        r = r*10 + (ch - '0');
        ch = getchar();
    }
    return r;
}

const int MOD = 998244353;
int a[5005], n, ans = 0;

void dfs(int step, int sum, int maxn)
{
    if (step > n)
    {
        if (sum > maxn*2)
            ans = (ans + 1) % MOD;
        return ;
    }
    dfs(step + 1, sum, maxn);
    dfs(step + 1, sum + a[step], max(maxn, a[step]));
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = fread();
    for (int i = 1; i <= n; i++)
        a[i] = fread();
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}









