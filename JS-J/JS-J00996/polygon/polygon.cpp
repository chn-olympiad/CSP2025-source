#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 998244353;

int n, a[5005];
int ans;
bool vis[5005];

void dfs(int step, int m, int sum, int maxl)
{
    if (sum <= maxl * 2) return;
    if (step > m)
    {
        ans = (ans + 1 + mod) % mod;
        return;
    }

    for (int i = 1;i <= n;i++)
    {
        vis[i] = 1;
        dfs(step + 1, m, sum + a[i], max(sum + a[i], maxl));
        vis[i] = 0;
        dfs(step + 1, m, sum, maxl);
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    if (n == 3)
    {
        int sum = 0;
        int maxl = -1;
        for (int i = 1;i <= n;i++)
        {
            sum += a[i];
            maxl = max(maxl, a[i]);
        }
        if (sum > 2 * maxl)
            printf("1 \n");
        return 0;
    }
    for (int i = 3;i <= n;i++)
    {
        dfs(0, i, 0, -1);
    }
    printf("%d \n",ans % mod);
    return 0;
}
