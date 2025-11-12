#include<bits/stdc++.h>
using namespace std;
vector<int> g[1010];
int w[1000010],c[20],a[20][1010],cnt[1010],u[1000010],v[1000010],vis[1010];
int fa[1010];
int fd(int x)
{
    if(fa[x] == x) return x;
    return fd(fa[x]);
}
struct node
{
    int maxn = -1,mmaxn = -1,id;
}t[1000010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        fa[max(u[i],v[i])] = min(u[i],v[i]);
        fa[min(u[i],v[i])] = min(u[i],v[i]);
    }
    if(k == 0)
    {
        for(int i = 1; i <= n; i++)
        {
            cnt[fd(i)]++;
        }
        for(int i = 1; i <= n; i++)
        {
            t[fd(i)].maxn = max(t[fd(i)].maxn,w[fd(i)]);
            t[fd(i)].id = fd(i);
            if(w[fd(i)] != t[fd(i)].maxn) t[fd(i)].mmaxn = max(t[fd(i)].mmaxn,w[fd(i)]);
        }
        for(int i = 1; i <= m; i++)
        {
            ans += w[i];
        }
        for(int i = 1; i <= n; i++)
        {
            if(vis[t[fd(i)].id] == 0)
            {
                ans -= t[fd(i)].maxn;
                vis[t[fd(i)].id] = 1;
            }
        }
        cout << ans << endl;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    return 0;
}
