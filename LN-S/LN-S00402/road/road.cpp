#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+50,M = 1e6+1e5+10;
int n,m,k,ecnt;
ll ret = 0,ans = LLONG_MAX;
bool sel[20];
ll val[20];
struct edge{int u,v,of;ll w;}e[M];
bool cmp(edge a,edge b){return a.w<b.w;}
struct disjoint_set_union
{
    int fa[N+10];
    void init(int mx){for(int i = 1;i<=mx;i++)fa[i]=i;return;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int x,int y){x=find(x),y=find(y),fa[x]=y;return;}
}dsu;
void kruskal(int sed)
{
    int cnt = 0;
    dsu.init(n+k);
    for(int i = 1;i<=ecnt;i++)
    {
        int x = dsu.find(e[i].u),y = dsu.find(e[i].v),fro = e[i].of;
        ll w = e[i].w;
        if(x==y||sel[fro]==0)continue;
        dsu.merge(x,y),ret+=w,cnt++;
        if(ret>ans||cnt>=n+sed-1)break;
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=m;i++)++ecnt,scanf("%d%d%lld",&e[ecnt].u,&e[ecnt].v,&e[ecnt].w),e[ecnt].of=0;
    for(int i = 1;i<=k;i++)
    {
        scanf("%lld",&val[i]);
        for(int j = 1;j<=n;j++)
        {
            ++ecnt;
            e[ecnt].u = n+i;
            e[ecnt].of = i;
            e[ecnt].v = j;
            scanf("%lld",&e[ecnt].w);
        }
    }
    sel[0] = 1;
    sort(e+1,e+1+ecnt,cmp);
    for(int i = 0;i<(1<<k);i++)
    {
        ret = 0;
        int sed = 0;
        for(int j = 0;j<k;j++)
            if(i>>j&1)sel[j+1] = 1,ret+=val[j+1],sed++;
            else sel[j+1] = 0;
        kruskal(sed);
        ans = min(ans,ret);
    }
    printf("%lld\n",ans);
    return 0;
} 