#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
struct Edge
{
    int u, v, w, nxt;
}edge[MAXN];
int head[MAXN], cnt;
void add(int u, int v, int w)
{
    edge[++cnt]={u, v, w, head[u]};
    head[u]=cnt;
}
int n, m, k;
int fa[MAXN], sum[MAXN];
int find(int i)
{
    if(fa[i]==i) return i;
    return fa[i]=find(fa[i]);
}

bool cmp(Edge x, Edge y)
{
    return x.w<y.w;
}
bool book[MAXN];
bool city[MAXN];
int a[MAXN];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    //printf("%d %d %d", n, m, k);
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        //add(v, u, w);
    }
    for(int i=1; i<=k; i++)
    {
        int t;
        scanf("%d", &t);
        int u=n+i;
        a[u]=t;
        for(int v=1; v<=n; v++)
        {
            int w;
            scanf("%d", &w);

            add(u, v, w+t);
            //add(v, u, w+t);
        }
    }
    m+=n*k;
    for(int i=1; i<=m; i++) fa[i]=i;;
    for(int i=1; i<=n; i++) sum[i]=1;
    sort(edge+1, edge+1+m, cmp);
    long long ans=0;

    //for(int i=1; i<=cnt; i++) printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
    //printf("\n");
    for(int i=1; ; i++)
    {
        int u=edge[i].u, v=edge[i].v, w=edge[i].w;
        if(book[u]&&book[v]) continue;
        book[u]=1, book[v]=1;
        if(u>n&&city[u]==0)
        {
            city[u]=1;
            for(int j=i; j<=m; j++)
            {
                if(edge[j].u==u) edge[j].w-=a[u];
            }
            sort(edge+i+1, edge+1+m, cmp);
            ans+=a[u];
            w-=a[u];
        }
        //printf("%d %d %d\n", u, v, w);
        ans+=w;
        int fu=find(u), fv=find(v);
        fa[fu]=fv;
        sum[fv]+=sum[fu];
        if(sum[fv]>=n) break;

    }
    printf("%lld", ans);
    return 0;
}
