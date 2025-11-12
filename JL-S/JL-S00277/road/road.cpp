#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e5+5;
struct edge
{
    int x,y,w;
    friend bool operator <(edge u,edge v)
    {
        if(u.w!=v.w) return u.w<v.w;
        if(u.x!=v.x) return u.x<v.x;
        return u.y<v.y;
    }
}e[M];
int par[N],n,m,k,u,v,z,cost[N];
long long ans;
int getroot(int x)
{
    if(par[x]==-1) return x;
    par[x]=getroot(par[x]);
    return par[x];
}
void un(int x,int y)
{
    int f1=getroot(x),f2=getroot(y);
    if(f1!=f2) par[f1]=f2;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    memset(par,-1,sizeof(par));
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&z);
        e[i].x=u;
        e[i].y=v;
        e[i].w=z;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",cost[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&z);
            e[m+n*(i-1)+j].x=n+i;
            e[m+n*(i-1)+j].y=j;
            e[m+n*(i-1)+j].w=z;
        }
    }
    bool flag=true;
    for(int i=1;i<=k;i++)
    {
        if(cost[i]!=0)
        {
            flag=false;
            break;
        }
    }
    for(int i=m+1;i<=m+n*k&&flag;i++)
    {
        if(e[i].w!=0) flag=false;
    }
    if(flag&&k!=0)
    {
        printf("0");
        return 0;
    }
    sort(e+1,e+1+n);
    int cnt=0;
    for(int i=1;i<=m+n*k;i++)
    {
        if(getroot(e[i].x)!=getroot(e[i].y))
        {
            un(e[i].x,e[i].y);
            ans+=e[i].w;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    printf("%lld",ans);
    return 0;
}
