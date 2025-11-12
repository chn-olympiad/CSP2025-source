#include<bits/stdc++.h>
using namespace std;
struct edg{
    int x,y,w;
};
bool cmp(edg x,edg y)
{
    return x.w<y.w;
}
int n,m,k;
edg g[1000005];
int fa[20005];
int c[20005];
int rt(int x)
{
    return x==fa[x]?x:fa[x]=rt(fa[x]);
}
void mg(int x,int y)
{
    fa[rt(x)]=rt(y);
}
edg g1[15][20005];
int g1p[15];
int g1n=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>g[i].x>>g[i].y>>g[i].w;
    }
    sort(g+1,g+m+1,cmp);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=g[i].x,y=g[i].y,w=g[i].w;
        if(rt(x)!=rt(y))
        {
            mg(x,y);
            g1[0][++g1n]=g[i];
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            g1[i][j].x=n+i,g1[i][j].y=j;
            cin>>g1[i][j].w;
        }
        sort(g1[i]+1,g1[i]+n+1,cmp);
    }
    for(int i=0;i<=k;i++)
        g1[i][n+1].w=1e9+7;
    long long minn=1e18;
    for(int bo=0;bo<(1<<k);bo++)
    {
        long long sum=0;
        int par=n;
        g1p[0]=1;
        for(int i=1;i<=k;i++)
        {
            if(bo&(1<<(i-1)))
                par++,sum+=c[i];
            g1p[i]=1;
        }
        for(int i=1;i<=n+k;i++)
            fa[i]=i;
        while(par>1)
        {
            int minw=1e9+5,minx;
            for(int i=0;i<=k;i++)
            {
                if(i==0 || (bo&(1<<(i-1))))
                {
                    if(g1[i][g1p[i]].w<minw)
                    {
                        minw=g1[i][g1p[i]].w;
                        minx=i;
                    }
                }
            }
            edg e=g1[minx][g1p[minx]];
     //       cout<<minx<<" "<<bo<<" "<<e.x<<" "<<e.y<<" "<<e.w<<"\n";
            g1p[minx]++;
            if(rt(e.x)!=rt(e.y))
            {
                mg(e.x,e.y);
                par--;
                sum+=e.w;
            }
        }
        minn=min(minn,sum);
    }
    cout<<minn;
    return 0;
}
