#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
int n,m,k,cun[N],cnt,f[N],sz[N];
long long ans = 0;
struct edge
{
    int u,v,w;
}a[2*M];
bool cmp(edge x,edge y)
{
    return x.w < y.w;
}
int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
}
void merge(int x,int y,int z)
{
    x = find(x),y = find(y);
    if(sz[x] > sz[y]) swap(x,y);
    if(x != y){
        ans += z;
        f[x] = y;
        sz[y] += sz[x];
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    cnt = m;
    for (int i = 1;i<=k;i++)
    {
        int x = 0;
        for (int i = 0;i<=n;i++){
            scanf("%d",&cun[i]);
            if(cun[i] == 0) x = i;
        }
        for (int i = 1;i<=n;i++)
            if(i != x)
                a[++cnt] = edge{i,x,cun[i]};
    }
    sort(a+1,a+1+cnt,cmp);
    for (int i = 1;i<=n;i++)
        f[i] = i,sz[i] = 1;
    for (int i = 1;i<=cnt;i++)
    {
        int u = a[i].u,v = a[i].v,w = a[i].w;
        merge(u,v,w);
    }
    printf("%lld\n",ans);
    return 0;
}