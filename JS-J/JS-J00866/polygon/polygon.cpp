#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5005, P = 998244353;
int n, ans;
int a[N];
bool used[N];
ll f[N];

void dfs(int dep, int mx, int sum, int cnt)
{
    if (dep > n)
    {
        ans += (sum > 2 * mx) && (cnt >= 3);
        if (ans >= P)
            ans -= P;
        return;
    }
    used[dep] = 1;
    dfs(dep + 1, max(mx, a[dep]), sum + a[dep], cnt + 1);
    used[dep] = 0;
    dfs(dep + 1, mx, sum, cnt);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    bool pflg = 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), pflg &= (a[i] == 1);
    if (pflg)
    {
        for (int i = 2; i <= n; ++i)
            (f[i] = f[i - 1] * 2ll + 1) %= (ll)P;
        for (int i = 1; i <= n; ++i)
            (f[i] += f[i - 1]) %= (ll)P;
        for (int i = 1; i <= n; ++i)
            (f[i] += f[i - 1]) %= (ll)P;
        printf("%lld\n", f[n - 1]);
        return 0;
    }
    sort(a + 1, a + n + 1);
    dfs(1, 0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
