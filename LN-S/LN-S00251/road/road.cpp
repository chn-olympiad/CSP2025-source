#include <bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10005],csh[15],facsh[15][10005],ans,ycsh[15],bcsh[15];
struct edge
{
    long long u,v,c;
}ed[1000005];
bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
int finfa(int x)
{
    if(fa[x]!=x)
        fa[x]=finfa(fa[x]);
    return fa[x];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>ed[i].u>>ed[i].v>>ed[i].c;
    }
    sort(ed+1,ed+m+1,cmp);
    for(int i=1;i<=k;i++)
    {
        cin>>csh[i];
        ycsh[i]=csh[i];
        for(int j=1;j<=n;j++)
        {
            cin>>facsh[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        long long u=ed[i].u,v=ed[i].v,c=ed[i].c,fu=finfa(u),fv=finfa(v),mincsh=-1;
        if(fu!=fv)
        {
            for(int j=1;j<=k;j++)
            {
                if(csh[j]+facsh[j][fu]+facsh[j][fv]<c)
                {
                    mincsh=j;
                    c=csh[j]+facsh[j][fu]+facsh[j][fv];
                }
            }
            for(int j=1;j<=k;j++)
            {
                if(facsh[j][fu]+facsh[j][fv]<c&&mincsh!=j)
                {
                    csh[j]+=facsh[j][fu]+facsh[j][fv]-c;
                }
            }
            if(mincsh!=-1)
            {
                csh[mincsh]=0;
                facsh[mincsh][fu]=0;
                facsh[mincsh][fv]=0;
            }
            fa[fu]=fv;
            for(int j=1;j<=k;j++)
            {
                facsh[j][fv]=min(facsh[j][fu],facsh[j][fv]);
            }
            ans+=c;
        }
    }
    cout<<ans;
}
