#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+10,K=20,inf=1e18;
struct node
{
    long long v,w;
};
struct edge
{
    long long u,v,w;
    bool operator <(const edge opt) const
    {
        return w<opt.w;
    }
}e[N];
long long n,m,k,c[K],a[K][N],ans=inf;
long long adj[N][N];
long long fa[N];
long long find(long long x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void merge(long long x,long long y){fa[find(x)]=find(y);}
long long kruskal()
{
    long long cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(find(e[i].u)==find(e[i].v)) continue;
        cnt+=e[i].w;
        merge(e[i].u,e[i].v);
    }
    return cnt;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)
    {
        for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(e+1,e+m+1);
        cout<<kruskal();
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            adj[u][v]=adj[v][u]=w;
        }
        for(int i=1;i<=k;i++)
        {
            cin>>c[i];
            if(c[i]==0)
            {
                long long s;
                for(int j=1;j<=n;j++)
                {
                    cin>>a[i][j];
                    if(a[i][j]==0) s=j;
                }
                for(int j=1;j<=n;j++)
                {
                    if(adj[s][j]==0) adj[s][j]=adj[j][s]=a[i][j];
                    else adj[s][j]=adj[j][s]=min(adj[s][j],a[i][j]);
                }
            }
        }
        long long tot=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(adj[i][j]!=0) e[++tot]=edge{i,j,adj[i][j]};
        sort(e+1,e+tot+1);
        m=tot;
        //for(int i=1;i<=m;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
        for(int i=1;i<=n;i++) fa[i]=i;
        cout<<kruskal();
    }
    return 0;
}
