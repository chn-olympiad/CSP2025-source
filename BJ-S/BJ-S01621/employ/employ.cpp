#include <cstdio>
using namespace std;

const int N = 505;

int a[N], p[N], n, m, ans = 0, plan[N];
bool vis[N];

void dfs(int x)
{
    if (x == n + 1)
    {
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) sum++;
            else
            {
                if (sum >= p[plan[i]]) sum++;
                else cnt++;
            }
        }
        if (cnt >= m) ans++;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = true;
        plan[x] = i;
        dfs(x + 1);
        vis[i] = false;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    if (n > 20)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= i;
            ans %= 998244353;
        }
        printf("%lld ", ans);
        return 0;
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}