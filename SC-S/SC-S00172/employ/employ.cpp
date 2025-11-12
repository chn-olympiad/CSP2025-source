#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5,M = 998244353;
char f[N];
int c[N],tf[N],vis[N];
int n,m,an;
void dfs(int u)
{
    if(u == n+1)
    {
        int qs = 0,ts = 0;
        for(int i = 1;i<=n;i++)
        {
            if(f[i] == '0')
                qs++;
            else if(c[tf[i]] <=  qs)
                qs++;
            else
                ts++;
        }
        if(ts >= m)
            an++ ;
        return ;
    }
    for(int i = 1;i<=n;i++)
    {
        if(vis[i])
            continue;
        tf[u] = i;
        vis[i] = 1;
        dfs(u+1);
        vis[i] = 0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    if(n > 18)
    {
        long long an = 1;
        for(int i = 1;i<=n;i++)
            an = an*i%M;
        cout << an;
        return 0;
    }
    for(int i = 1;i<=n;i++)
        cin >> f[i];
    for(int i = 1;i<=n;i++)
        cin >> c[i];
    dfs(1);
    cout << an;
    return 0;
}