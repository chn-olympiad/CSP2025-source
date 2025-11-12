#include <cstdio>
#include <algorithm>
#define project int
#define sekai main
#define pjsk 505
#define ll long long
using namespace std;
const int mod = 998244353;
int s[pjsk], c[pjsk], n, m;
int tmp[pjsk];
bool vis[pjsk];
ll ans = 0;
void dfs(int dep)
{
    if(dep == n + 1)
    {
        int cnt = 0, cntfq = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] && c[tmp[i]] > cntfq)
            {
                cnt += 1;
                if(cnt >= m)
                {
                    ans += 1;
                    ans %= mod;
                    return ;
                }
            }
            else
            {
                cntfq += 1;
            }
        }
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            tmp[dep] = i;
            vis[i] = 1;
            dfs(dep + 1);
            vis[i] = 0;
        }
    }
}
project sekai()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    char ss[pjsk];
    scanf("%s", ss + 1);
    for(int i = 1; i <= n; i++)
    {
        s[i] = ss[i] - '0';
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    dfs(1);
    printf("%lld", ans % mod);
    return 0;
}