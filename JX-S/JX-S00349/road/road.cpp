#include<bits/stdc++.h>
using namespace std;
const int mn=1e4+45,mm=1e6+5;
typedef long long ll;
int n,m,k;
struct edge
{
    int u,v,w;
}a[mm],b[mm];
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int tp;
ll ans,tans;
int c[mn];// cost of country -> city
int fa[mn];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
bool isok[mn];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    ans=tans=0;
    for(int i=1;i<=m;i++)
    {
        int u=find(a[i].u),v=find(a[i].v);
        if(u==v)continue;
        tans+=a[i].w;
        b[++tp]=a[i];
        fa[u]=v;
        if(tp==n-1)break;
    }
    ans=tans;
    int x;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            b[++tp]={n+i,j,x};
        }
    }
    sort(b+1,b+tp+1,cmp);
    for(int i=1;i<(1<<k);i++)
    {
        tans=0;
        int tot=n-1;
        for(int j=1;j<=k;j++)
        {
            isok[j]=i&(1<<(j-1));
            if(isok[j])
            {
                tans+=c[j];
                ++tot;
            }
        }
        for(int j=1;j<=n+k;j++)fa[j]=j;
        for(int j=1;j<=tp;j++)
        {
            if(b[j].u>n && !isok[b[j].u-n])continue;
            int u=find(b[j].u),v=find(b[j].v);
            if(u==v)continue;
            tans+=b[j].w;
            fa[u]=v;
            --tot;
            if(!tot)break;
        }
        ans=min(ans,tans);
    }
    printf("%lld\n",ans);
}