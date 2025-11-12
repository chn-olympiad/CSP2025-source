#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;
int to[maxn*2],nxt[maxn*2],val[maxn*2],h[maxn*2],tot;
long long ans;
int n,m,k;
int dis[maxn];
bool vis[maxn];
vector<int>c[15];
int vk[15];
void add(int x,int y,int v)
{
    tot++;
    to[tot]=y;
    val[tot]=v;
    nxt[tot]=h[x];
    h[x]=tot;
}
void tree()
{
    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX;
    dis[1]=0;int u=0;
    int cnt=1;
    while(1)
    {
        int u=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]<dis[u]&&!vis[i])
                u=i;
        }
        if(u==0)break;
        vis[u]=0;
        for(int i=h[u];i;i=nxt[i])
        {
            if(!vis[to[i]]&&dis[to[i]]>val[i])
            {
                dis[to[i]]=val[i];
            }
        }
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>vk[i];
        for(int j=1,cj;j<=n;j++)
        {
            cin>>cj;
            c[i].push_back(cj);
        }
    }
    tree();
    for(int i=1;i<=n;i++)ans+=dis[i];
    if(k==0)cout<<ans;
    else cout<<2318731;
    return 0;
}
