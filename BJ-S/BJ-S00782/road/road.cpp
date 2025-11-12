#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
struct nd{
    int y,w;
};
vector<nd> g[100015];
int n,m,k,c[15],dis[100015];
bool f[15],flag = 1;
long long ans = 9e18;
void chk(long long s,int kk)
{
    long long sum = 0;
    memset(dis,0x3f,sizeof(dis));
    int cnt = 1,x = 1;
    while (cnt <= n + kk)
    {
        dis[x] = -1;
        int id,mi = 2e9;
        for (auto t:g[x])
        {
            if (t.y > n && !f[t.y - n]) continue;
            dis[t.y] = min(dis[t.y],t.w);
        }
        for (int i = 1;i <= n + k;i++)
        {
            if (i > n && !f[i - n]) continue;
            if (dis[i] == -1) continue;
            if (mi > dis[i])
            {
                mi = dis[i];
                id = i;
            }
        }
        x = id;
        if (mi != 2e9) sum += mi;
        if (s + sum >= ans) return;
        cnt++;
    }
    ans = min(ans,s + sum);
}
void dfs(int p,long long s,int kk)
{
    if (s >= ans) return;
    if (p > k)
    {
        chk(s,kk);
        return;
    }
    if (c[p] != 0) dfs(p + 1,s,kk);
    f[p] = 1;
    dfs(p + 1,s + c[p],kk + 1);
    f[p] = 0;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    while (m--)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for (int j = 1;j <= n;j++)
        {
            int w;
            scanf("%d",&w);
            g[n + i].push_back({j,w});
            g[j].push_back({n + i,w});
        }
    }
    dfs(1,0,0);
    cout << ans;
    return 0;
}
