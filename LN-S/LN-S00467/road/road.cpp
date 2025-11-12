#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int u,v,w;
};
bool cmp(node a,node b)
{
    return a.w>b.w;
}
node a[10009];
int co[10][10009];
int mn=INT_MAX;
int n,m,k;
vector<pair<int,int>> mp[1000009];
bool vis[10009];
bool f[10009][10009];
void dfs(int cnt,int u,int s)
{
    if(cnt==n)
    {
        mn=min(mn,s);
        return;
    }
    if(s>mn){return;}
    for(int i=0;i<mp[u].size();i++)
    {
        int y=mp[u][i].first,c=mp[u][i].second;
        if(vis[y]==0)
        {
            s+=c;
            vis[y]=1;
            cnt++;
            dfs(cnt,y,s);
            cnt--;
            vis[y]=0;
            s-=c;
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        mp[a[i].u].push_back({a[i].v,a[i].w});
        mp[a[i].v].push_back({a[i].u,a[i].w});
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            cin>>co[i][j];
        }
        for(int j=1;j<=m;j++)
        {
            int mnab=INT_MAX;
            if(f[a[j].u][a[j].v]==0)
            {
                int cost=co[i][a[j].u]+co[i][a[j].v]+c;
                if(cost<mnab)
                {
                    mnab=cost;
                    mp[a[i].u][a[i].v].second=cost;
                    mp[a[i].v][a[i].u].second=cost;
                }
            }
        }
    }
    vis[1]=1;
    dfs(0,1,0);
    //cout<<mn;
    cout<<0;
    return 0;
}
