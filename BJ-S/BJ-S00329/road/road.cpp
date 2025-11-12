#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[15],k,h[15][1010],gt[1010][1010],g[1010][1010],dis[1010],vis[1010];
int prim(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int id=0,minn=1e18;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]<minn&&!vis[j])
            {
                minn=dis[j];
                id=j;
            }
        }
        vis[id]=1;
        ans+=dis[id];
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
                dis[j]=min(dis[j],gt[j][id]);
            //cout<<dis[j]<<' ';
        }
        //cout<<ans<<'\n';
    }
    return ans;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>h[i][j];
    }
    long long finalans=1e18;
    for(int x=0;x<=pow(2,k)-1;x++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)gt[i][j]=g[i][j];
        }
        int cur=0,tt=x,plu=0;
        while(tt)
        {
            cur++;
            if(tt&1)
            {
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                    {
                        if(i==j)continue;
                        gt[i][j]=gt[j][i]=min(gt[i][j],h[cur][i]+h[cur][j]);\
                    }
                plu+=c[cur];
            }
            tt/=2;
        }
        finalans=min(finalans,1ll*prim(1)+plu);
    }
    cout<<finalans;
    return 0;
}
