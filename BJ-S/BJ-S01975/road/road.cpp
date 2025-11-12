#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k;
struct edge
{
    int u,v,w;
    bool operator<(const edge &o)const
    {
        return w<o.w;
    }
};
vector<edge>adj;
vector<bool> chs;
int w[10];
int a[10][N];
int nod;
int pre[N];
int ans=0x3f3f3f3f;
vector<edge>tmp;
int find(int x)
{
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
void easy()
{
    nod=n;
    int res=0;
    adj=tmp;
    for(int i=1; i<=k; i++)
    {
        if(chs[i]==1)
        {
            nod++;
            res+=w[i];
            for(int j=1; j<=n; j++)
            {
                adj.push_back({nod,j,a[i][j]});
            }
        }
    }
    if(res>=ans) return;
    for(int i=1; i<=nod; i++) pre[i]=i;
    sort(adj.begin(),adj.end());
    for(int i=0; i<adj.size(); i++)
    {
        int u=adj[i].u;
        int v=adj[i].v;
        int w=adj[i].w;
        int fu=find(u);
        int fv=find(v);
        if(fu!=fv)
        {
            pre[fu]=fv;
            if(res>=ans) return;
            res+=w;

        }

    }
    ans=min(ans,res);
    return;
}
void dfs(int syt)
{
    if(syt==k)
    {
        easy();
        return;
    }
    chs.push_back(0);
    dfs(syt+1);
    chs.pop_back();
    chs.push_back(1);
    dfs(syt+1);
    chs.pop_back();
    return;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }

    tmp=adj;
    int maxn=-0x3f3f3f3f;
    for(int i=1; i<=k; i++)
    {
        cin>>w[i];
        maxn=max(maxn,w[i]);
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    if(maxn>0)
    {
        dfs(0);
        cout<<ans<<'\n';
    }
    else
    {
        for(int i=1; i<=k; i++)chs.push_back(1);
        easy();
        cout<<ans<<'\n';
    }

    return 0;
}
