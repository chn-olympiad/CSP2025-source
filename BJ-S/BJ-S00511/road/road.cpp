#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=2e6+5;
struct node
{
    int u,v;
    ll w;
    bool operator <(node _)
    {
        return w<_.w;
    }
}edge[M];
int fa[N];
ll a[15][N],c[N];
int findRt(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=findRt(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    bool flag=1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0) flag=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(flag)
    {
        int cnt=m;
        ll res=0;
        for(int j=1;j<=k;j++)
        {
            for(int i=1;i<=n;i++)
            {
                edge[++cnt].u=n+j;
                edge[cnt].v=i;
                edge[cnt].w=a[j][i];
            }
        }
        sort(edge+1,edge+cnt+1);
        for(int i=1;i<=n+k+1;i++) fa[i]=i;
        for(int i=1;i<=cnt;i++)
        {
            int fx=findRt(edge[i].u),fy=findRt(edge[i].v);
            if(fx!=fy)
            {
                res+=edge[i].w;
                fa[fx]=fy;
            }
        }
        cout<<res;
        return 0;
    }
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++)
    {
        int cnt=m;
        ll res=0;
        for(int j=k-1;j>=0;j--)
        {
            if((i>>j)&1)
            {
                res+=c[j+1];
                for(int o=1;o<=n;o++)
                {
                    edge[++cnt].u=n+j+1;
                    edge[cnt].v=o;
                    edge[cnt].w=a[j+1][o];
                }
            }
        }
        sort(edge+1,edge+cnt+1);
        for(int j=1;j<=n+k+1;j++) fa[j]=j;
        for(int j=1;j<=cnt;j++)
        {
            int fx=findRt(edge[j].u),fy=findRt(edge[j].v);
            if(fx!=fy)
            {
                res+=edge[j].w;
                fa[fx]=fy;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
