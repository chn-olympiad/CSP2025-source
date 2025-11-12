#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;

#define N 10005
#define M 2000025
#define K 13
#define INF 1047483647

ll n,m,k,id;
ll e[M],nxt[M],h[N],w[M];
ll c[K],lnk[K][N];
bool gaid[K];
ll q[N];

ll dis[N];
bool bj[N];

void add(ll x,ll y,ll z)
{
    e[id]=y;
    nxt[id]=h[x];
    w[id]=z;
    h[x]=id++;
}

void shu()
{
    ll u=1,ans=0;
    for(int tt=1;tt<n;tt++)
    {
        memset(q,0,sizeof q);
        //zhao zui duan
        //xiulu
        for(int i=h[u];~i;i=nxt[i])
        {
            ll v=e[i],d=w[i];
            if(d<dis[v])
                dis[v]=d;
        }
        //gaizao
        for(int v=1;v<=n;v++)
        {
            if(bj[v])continue;
            for(int j=1;j<=k;j++)
            {
                ll d=(1-gaid[j])*(c[j]+lnk[j][u])+lnk[j][v];
                if(d<dis[v])
                    dis[v]=d,q[v]=j;//yaogaizaocaixing
            }
        }
        ll p,mdis=INF;
        for(int i=1;i<=n;i++)
        {
            if(!bj[i] && dis[i]<mdis)
                p=i,mdis=dis[i];
        }
        if(q[p])gaid[q[p]]=1;
        bj[p]=1;
        u=p;
        ans+=mdis;
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(h,-1,sizeof h);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>lnk[i][j];
        }
    }
    for(int i=2;i<=n;i++)
        dis[i]=INF;
    bj[1]=1;

    shu();

    return 0;
}



