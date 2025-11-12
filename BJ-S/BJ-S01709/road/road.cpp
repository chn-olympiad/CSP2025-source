#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int M=1e4+5;
int n,m,k,num,cnt;
int fa[M];
int a[15][10005],c[15];
struct node{
    int u,v,w;
}e[N];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fax=find(x);
    fa[fax]=y;
}
int f()
{
    int ans=0;
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int v=e[i].v,u=e[i].u,w=e[i].w;
        if(find(u)==find(v)) continue;
        ans+=e[i].w;
        merge(u,v);
    }
    return ans;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[++cnt].u=u,e[cnt].v=v,e[cnt].w=w;
    }
    for(int i=1;i<=n+k;i++) fa[i]=i;
    if(k<=0)
    {
        cout<<f()<<endl;
        return 0;
    }
    int flag=0;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]) flag=1;
        int f1=1;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            f1=f1&(a[i][j]>0);
        }
        flag|=f1;
    }
    if(!flag)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                e[++cnt].u=i+n,e[cnt].v=j,e[cnt].w=a[i][j];
            }
        }
        cout<<f()<<endl;
        return 0;
    }
    return 0;
}