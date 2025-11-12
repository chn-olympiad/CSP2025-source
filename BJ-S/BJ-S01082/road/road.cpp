#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e5+5,M=1e6+5,C=1e4+5;
struct node
{
    int u,v,w;
}edge[N],cty[M],bst[N],rd[11][C],tmp[N];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int n,m,k,f[N],bsttot,cst[N],ans=1e18,sum,tot;
int findfa(int x)
{
    if(f[x]==x)return x;
    else return f[x]=findfa(f[x]);
}
void merge(int x,int y)
{
    int fx=findfa(x),fy=findfa(y);
    f[fx]=fy;
}
void init()
{
    for(int i=1;i<=n+k;i++)
    {
        f[i]=i;
    }
}
void mg(int p)
{
    int p1=1,p2=1;
    for(int i=1;i<=tot;i++)tmp[i]=edge[i];
    tot=tot+n;
    for(int i=1;i<=tot;i++)
    {
        if(p1>tot-n)
        {
            edge[i]=rd[p][p2++];
        }
        else if(p2>n)
        {
            edge[i]=tmp[p1++];
        }
        else if(rd[p][p2].w<tmp[p1].w)
        {
            edge[i]=rd[p][p2++];
        }
        else
        {
            edge[i]=tmp[p1++];
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    faster;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> cty[i].u >> cty[i].v >> cty[i].w;
    }
    sort(cty+1,cty+m+1,cmp);
    init();
    for(int i=1;i<=m;i++)
    {
        int x=cty[i].u,y=cty[i].v;
        if(findfa(x)!=findfa(y))
        {
            bst[++bsttot]=cty[i];
            merge(x,y);
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin >> cst[i];
        for(int j=1;j<=n;j++)
        {
            edge[j].u=n+i;
            edge[j].v=j;
            cin >> edge[j].w;
        }
        sort(edge+1,edge+n+1,cmp);
        for(int j=1;j<=n;j++)
        {
            rd[i][j]=edge[j];
        }
    }
    for(int sta=0;sta<(1<<k);sta++)
    {
        for(int i=1;i<=n-1;i++)
        {
            edge[i]=bst[i];
        }
        tot=n-1;sum=0;
        init();
        for(int i=1;i<=k;i++)
        {
            if(sta&(1<<i-1))
            {
                sum+=cst[i];
                mg(i);
            }
        }
        for(int i=1;i<=tot;i++)
        {
            int x=edge[i].u,y=edge[i].v;
            if(findfa(x)!=findfa(y))
            {
                sum+=edge[i].w;
                if(sum>ans)break;
                merge(x,y);
            }
        }
        ans=min(ans,sum);
    }
    cout << ans;
    return 0;
}