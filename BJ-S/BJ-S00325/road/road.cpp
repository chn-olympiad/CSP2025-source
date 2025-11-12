#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct road
{
    int u,v,w;
}r[1100005];
bool cmp(road x,road y)
{
    return x.w<y.w;
}
int c[12],fa[10015],sz[12],bs[12][10015],n,m,k,cz;
int getfa(int x)
{
    if(fa[x]==x)return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
bool vis[12];
long long dist[12][10015],an=1e18;
void dfs(int x)
{
    if(x>k)
    {
        int x,y,i;
        long long ans=0;
        for(i=1;i<=n+k;i++)
            fa[i]=i;
        for(i=1;i<=m+k*n;i++)
        {
            if(r[i].v>n&&!vis[r[i].v-n])continue;
            x=getfa(r[i].u),y=getfa(r[i].v);
            if(x!=y)
            {
                fa[y]=x;
                ans+=r[i].w;
            }
        }
        an=min(an,ans+cz);
        return;
    }
    dfs(x+1);
    vis[x]=1,cz+=c[x];
    dfs(x+1);
    vis[x]=0,cz-=c[x];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int dq,x,y,wz,i,j;
    long long cost;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
    for(i=1;i<=k;i++)
    {
        scanf("%d",c+i);
        for(j=1;j<=n;j++)
        {
            dq=m+(i-1)*n+j;
            scanf("%d",&r[dq].w);
            r[dq].u=j,r[dq].v=n+i;
        }
    }
    dq=m+k*n;
    sort(r+1,r+dq+1,cmp);
    if(k<=5)
    {
        dfs(1);
        cout<<an;
        return 0;
    }
    for(i=1;i<=n+k;i++)
        fa[i]=i;
    memset(dist,-1,sizeof(dist));
    for(i=1;i<=dq;i++)
    {
        x=getfa(r[i].u),y=getfa(r[i].v);
        if(x!=y)
        {
            fa[y]=x;
            an+=r[i].w;
            for(j=1;j<=k;j++)
                if(dist[j][y]!=-1)
                    dist[j][x]=dist[j][y],bs[j][x]=bs[j][y];
            if(r[i].v>n)
            {
                dist[r[i].v-n][y]+=r[i].w;
                bs[r[i].v-n][y]++;
                sz[r[i].v-n]++;
                if(!vis[r[i].v-n])
                {
                    vis[r[i].v-n]=1;
                    an+=c[r[i].v-n];
                }
            }
        }
        else if(r[i].u<=n&&r[i].v<=n)
        {
            cost=0;
            for(j=1;j<=k;j++)
            {
                if(bs[j][x]==2)
                {
                    cost=max(cost,dist[j][x]+c[j]);
                    wz=j;
                }
            }
            if(cost>r[i].w)
            {
                an=an-cost+r[i].w;
                dist[wz][x]=-1,bs[wz][x]=0;
                if(sz[wz]==2)
                    vis[wz]=0;
            }
        }
    }
    cout<<an;
    return 0;
}