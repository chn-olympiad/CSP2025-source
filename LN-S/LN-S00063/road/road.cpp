#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+16;
int n,m,k,f[maxn],c[15],gz[15][maxn],cnt;
long long ans;
struct edge
{
    int from,to;
    long long val;
}ed[maxn];
int find(int x)
{
    if(x==f[x])return x;
    else
    {
        f[x]=find(f[x]);
        return f[x];
    }
}
void join(int a,int b)
{
    f[find(a)]=find(b);
}
bool cmp(edge a,edge b)
{
    return a.val<b.val;
}
inline void kruskal()
{
    sort(ed+1,ed+m+k+1,cmp);
    for(int i=1;i<=m+k*n;i++)
    {
        if(find(ed[i].from)==find(ed[i].to))continue;
        ans+=ed[i].val;
        join(ed[i].from,ed[i].to);
        cnt++;
        if(cnt==n+k-1)break;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m+k*n;i++)f[i]=i;
    for(int i=1;i<=m;i++)cin>>ed[i].from>>ed[i].to>>ed[i].val;
    if(k==0)
    {
        kruskal();
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            cin>>c[i];//c[i]==0
            for(int j=1;j<=n;j++)
            {
                cin>>gz[i][j];
                ed[m+(i-1)*n+j].from=m+i;
                ed[m+(i-1)*n+j].to=j;
                ed[m+(i-1)*n+j].val=gz[i][j];
            }
        }
        kruskal();
        cout<<ans;
    }
    return 0;
}
