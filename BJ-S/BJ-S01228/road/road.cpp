#include <bits/stdc++.h>
#define N 2000005

using namespace std;

int n,m,k,fa[N],cnt,ans,add[N];
struct edge
{
    int u,v,w;
}e[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
    int dx=find(x),dy=find(y);
    if(dx!=dy)fa[dx]=dy;
}
bool cmp(edge x,edge y){return x.w<y.w;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        int x,mn=1e9,tmp=0;
        cin>>x;
        for(int j=1;j<=n;j++)
            cin>>add[j];
        for(int j=1;j<=n;j++)
        {
            e[(i-1)*n+j+m].u=i+n;
            e[(i-1)*n+j+m].v=j;
            e[(i-1)*n+j+m].w=add[j]+x;
        }
    }
    sort(e+1,e+m+k*n+1,cmp);
    for(int i=1;i<=m+k*n;i++)
        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<n;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            merge(e[i].u,e[i].v);
            cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';
            ans+=e[i].w,cnt++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
