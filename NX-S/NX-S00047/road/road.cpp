#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
    int u,v,w;
    bool operator<(const Edge& a)const{return this->w<a.w;}
}e[2000005];
int n,m,k,u,v,w,cnt,c[15],a[15][20005],f[200005];
void init(int n){iota(f+1,f+n+1,1);}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}
bool check(int x,int y){return find(x)==find(y);}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&u,&v,&w),e[++cnt]={u,v,w};
    if (k==0)
    {
        init(n);
        sort(e+1,e+cnt+1);
        int sum=0,ans=0,it=1;
        while (sum<n-1)
        {
            if (!check(e[it].u,e[it].v))
                merge(e[it].u,e[it].v),sum++,ans+=e[it].w;
            it++;
            if (it>cnt) break;
        }
        printf("%lld",ans);
        return 0;
    }
    for (int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        int pos=0;
        for (int j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
            if (a[i][j]==0) pos=j;
        }
        for (int j=1;j<=n;j++)
        {
            if (j==pos) continue;
            e[++cnt]={pos,j,a[i][j]};
        }
    }
    init(n);
    sort(e+1,e+cnt+1);
    int sum=0,ans=0,it=1;
    while (sum<n-1)
    {
        if (!check(e[it].u,e[it].v))
            merge(e[it].u,e[it].v),sum++,ans+=e[it].w;
        it++;
        if (it>cnt) break;
    }
    printf("%lld",ans);
    return 0;
}