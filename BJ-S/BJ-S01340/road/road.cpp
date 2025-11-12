#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,i,j,c[10005],a[15][10005],fa[10005],sum,tot,minn=INT_MAX;
bool f=1;
struct Node
{
    int u,v,w;
    bool operator<(Node x)
    {
        return w<x.w;
    }
}e[2000005];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    fa[y]=x;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)f=0;
    for(i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    for(i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)f=0;
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)f=0;
        }
    }
    if(f)
    {
        cout<<0;
        return 0;
    }
    for(int Bit=0;Bit<(1<<k);Bit++)
    {
        int bit=Bit;
        tot=n;
        int cur=0;
        sum=0;
        while(bit)
        {
            ++cur;
            if(bit&1)
            {
                sum+=c[cur];
                for(i=1;i<=n;i++)e[++tot]={n+cur,i,a[cur][i]};
            }
            bit>>=1;
        }
        for(i=1;i<=n+k;i++)fa[i]=i;
        sort(e+1,e+tot+1);
        for(i=1;i<=tot;i++)
        {
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(find(u)==find(v))continue;
            merge(u,v);
            sum+=w;
        }
        minn=min(minn,sum);
    }
    cout<<minn;
    return 0;
}
