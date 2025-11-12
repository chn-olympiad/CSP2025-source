#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,fa[10005],ans=0,a[10005],c[15];
struct node
{
    int u,v,w;
}e[N];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){return a.w<b.w;}
void kruskal()
{
    sort(e,e+m,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++)
    {
        bool f=1;
        for(int j=1;j<n;j++)
            if(fa[i]!=fa[i+1])
            {
                f=0;
                break;
            }
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y)
        {
            fa[x]=y;
            ans+=e[i].w;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=N;i++) e[i].w=1e9;
    for(int i=0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    kruskal();
    int res=ans;
    if(k==0)
    {
        cout<<res;
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[j];
        for(int j=0;j<m;j++)
            if(a[e[j].u]+a[e[j].v]<e[j].w) e[j].w=a[e[j].u]+a[e[j].v];
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                e[++m].u=j,e[m].v=k,e[m].w=a[k]+a[j];
    }
    ans=0;
    kruskal();
    for(int i=n-k+1;i<=n;i++) if(find(i)==find(1)) ans+=c[i];
    cout<<min(ans,res);
    return 0;
}
