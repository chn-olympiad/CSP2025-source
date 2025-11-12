#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,u,v,w,a[11][N];
int dis[N];long long ans;
struct node
{
    int id,val;
};
vector<node> g[N];
void bfs(int x)
{
    queue<node> q;
    q.push({x,0});
    while (q.size())
    {
        node c=q.front();
        q.pop();
        for (int i=0;i<g[c.id].size();i++)
        {
            node d=g[c.id][i];
            if (dis[d.id]==0x3f3f3f3f)
            {
                q.push(d);
                for (int j=1;j<=k;j++)
                {
                    if (a[j][c.id]+a[j][d.id]+a[j][0]<d.val)
                    {
                        dis[d.id]=a[j][c.id]+a[j][d.id]+a[j][0]+dis[c.id];
                        a[j][c.id]=0;
                        a[j][d.id]=0;
                        a[j][0]=0;
                    }
                    else
                    {
                        dis[d.id]=1ll*d.val;
                        d.val=0;
                    }
                }
            }
        }
    }
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++)
        for (int j=0;j<=n;j++)
            cin>>a[i][j];
    bfs(1);
    cout<<dis[n];
    return 0;
}
