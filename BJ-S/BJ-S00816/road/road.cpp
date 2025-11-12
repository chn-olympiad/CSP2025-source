#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
};
node a[1000005];
node p[1024][10055];
int cnt[1024];
long long ans=1e18,cost[1024],temp;
int fa[10055],sz[10055];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int n,m,k;
void init()
{
    temp=0;
    for(int i=1;i<=n+k;i++)
        fa[i]=i,sz[i]=1;
}
int find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
    if(sz[u]>sz[v]) swap(u,v);
    fa[u]=v;
    sz[v]+=sz[u];
}
inline int lowbit(int x)
{
    return (x&(-x));
}
node b[15][10005];
int L[1024];
void solve(int x,int y)
{
    int now=L[y]+1;
    for(int i=1,j=1;i<=cnt[x];i++)
    {
        while(j<=n&&b[now][j].w<p[x][i].w)
        {
            int u=b[now][j].u,v=b[now][j].v,w=b[now][j].w;
            u=find(u),v=find(v);
            if(u!=v)
            {
                temp+=w;
                p[x+y][++cnt[x+y]]=b[now][j];
                merge(u,v);
            }
            j++;
        }
        int u=p[x][i].u,v=p[x][i].v,w=p[x][i].w;
        u=find(u),v=find(v);
        if(u!=v)
        {
            temp+=w;
            p[x+y][++cnt[x+y]]=p[x][i];
            merge(u,v);
        }
        if(i==cnt[x])
        {
            while(j<=n)
            {
                int u=b[now][j].u,v=b[now][j].v,w=b[now][j].w;
                u=find(u),v=find(v);
                if(u!=v)
                {
                    temp+=w;
                    p[x+y][++cnt[x+y]]=b[now][j];
                    merge(u,v);
                }
                j++;
            }
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    L[1]=0;
    for(int i=2;i<1024;i++)
        L[i]=L[i/2]+1;
    for(int i=1;i<=m;i++)
        cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>cost[1<<(i-1)];
        for(int j=1;j<=n;j++)
        {
             cin>>b[i][j].w;
             b[i][j].u=n+i,b[i][j].v=j;
        }
        sort(b[i]+1,b[i]+n+1,cmp);
    }
    sort(a+1,a+m+1,cmp);
    init();
    for(int i=1;i<=m;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        u=find(u),v=find(v);
        if(u!=v)
        {
            temp+=w;
            p[0][++cnt[0]]=a[i];
            merge(u,v);
        }
    }
    ans=min(ans,temp);
    for(int i=1;i<(1<<k);i++)
    {
        cost[i]=cost[lowbit(i)]+cost[i-lowbit(i)];
        init();
        temp=cost[i];
        solve(i-lowbit(i),lowbit(i));
        ans=min(ans,temp);
    }
    cout<<ans;
    return 0;
}
