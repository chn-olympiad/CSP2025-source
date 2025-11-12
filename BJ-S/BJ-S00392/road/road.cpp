#include<bits/stdc++.h>
using namespace std;
const int M=2e6+10;
const int N=1e4+10;
long long n,m,k,vis[N],inc[N],c[20],a[20][N];
struct road
{
    int u,v,w;
}g[M];
vector<int> p[N];
void dfs(int x,int f)
{
    vis[x]=1;inc[x]=1;
    for(auto k:p[x])
    {
        if(f==k) continue;
        dfs(k,x);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    priority_queue<pair<int,int> > q;
    for(int i=1;i<=m;i++)
    {
        cin>>g[i].u>>g[i].v>>g[i].w;
        q.push({-g[i].w,i});
    }
    long long ans=1e9;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0)
            {
                for(int t=1;t<=n;t++)
                {
                    if(j==t) continue;
                    g[++m]={j,t,a[i][t]};
                    q.push({-a[i][t],m});
                }
            }
        }
    }
    long long cnt=0,an=0;
    long long x=q.top().second;
    an+=q.top().first;
    vis[g[x].u]=vis[g[x].v]=1;cnt=1;
    inc[g[x].u]=inc[g[x].v]=1;
    q.pop();
    while(cnt<n-1)
    {
        long long x=q.top().second;
        q.pop();
        if(vis[g[x].u] and !vis[g[x].v])
        {
            cnt++;
            dfs(g[x].v,0);
            an-=g[x].w;
        }
        else if(vis[g[x].v] and !vis[g[x].u])
        {
            cnt++;
            dfs(g[x].u,0);
            an-=g[x].w;
        }
        else if(!inc[g[x].u] or !inc[g[x].v])
        {
            cnt++;
            inc[g[x].u]=1;inc[g[x].v]=1;
            p[g[x].v].push_back(g[x].u);
            p[g[x].u].push_back(g[x].v);
            an-=g[x].w;
        }
    }
    cout<<-an;
    return 0;
}
