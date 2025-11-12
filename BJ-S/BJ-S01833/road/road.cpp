#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool f=1;
long long ans;
struct node
{
    int t,w;
};
vector<node> v[10005];
struct edge
{
    int x,y,z;
}e[1000005];
bool cmp(edge i,edge j)
{
    return i.z<j.z;
}
int c[15];
int a[15][10005];
int fa[10005];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void kruskal()
{
    sort(e+1,e+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int fx=find(e[i].x);
        int fy=find(e[i].y);
        if(fx!=fy)
        {
            cnt++;
            ans+=e[i].z;
            fa[fx]=fy;
        }
        if(cnt==n-1)break;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        e[i]={x,y,z};
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=k;i++)
    {
        if(c[i]!=0)
        f=0;
    }
    if(f==1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int w=2e9+5;
                for(int p=1;p<=k;p++)w=min(w,a[p][i]+a[p][j]);
                e[++m]={i,j,w};
            }
        }
    }
    kruskal();
    printf("%lld",ans);
    return 0;
}
