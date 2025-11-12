#include <bits/stdc++.h>
#define int long long
using namespace std;
struct nd
{
    int u,v,w;
}a[1000005];
int n,m,k,ans=0;
int pa[1000005];
bool cmp(nd x,nd y)
{
    return x.w<y.w;
}
int getf(int x)
{
    return x==pa[x]?x:pa[x]=getf(pa[x]);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        int uu=getf(u),vv=getf(v);
        if(uu!=vv)
        {
            ans+=w;
            pa[vv]=uu;
        }
    }
    if(k==0)
        printf("%lld",ans);
    else
        printf("0");

    return 0;
}
