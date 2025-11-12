#include<bits/stdc++.h>
using namespace std;
struct bian{
    int u,v,w;
}e[10000005];
bool cmp(bian x,bian y)
{
    return x.w<y.w;
}
int fa[10000005];
int gtf(int x)
{
    return x==fa[x]?fa[x]:fa[x]=gtf(fa[x]);
}
void mg(int x,int y)
{
    x=gtf(x);
    y=gtf(y);
    fa[x]=y;
}
int c[20];
int w1[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int u1=m+1;
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int i=1;i<=n;i++)
        {
            cin>>w1[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int i1=i+1;i1<=n;i1++)
            {
                cin>>w1[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int i1=i+1;i1<=n;i1++)
            {
                e[u1].u=i;
                e[u1].v=i1;
                e[u1].w=w1[i]+w1[i1]+c[j];
                u1++;
            }
        }
    }
    m=u1-1;
    for(int i=1;i<=m;i++)
    {
        fa[i]=i;
    }
    sort(e+1,e+m+1,cmp);
    /*for(int i=1;i<=m;i++)
    {
        cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
    }*/
    long long ans=0;
    int lb=0;
    for(int i=1;lb<n-1;i++)
    {
        if(fa[e[i].u]==fa[e[i].v])
            continue;
        //cout<<e[i].u<<' '<<e[i].v<<endl;
        mg(e[i].u,e[i].v);
        ans+=e[i].w;
        lb++;
    }
    cout<<ans;
    return 0;
}
