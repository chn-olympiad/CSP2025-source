//感觉像最小生成树
//但我已经忘的差不多了
//不过好像跟最短路类似
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 1e3+5;
const int M = 1e6+5;

int s = 1;  //起点，随便选，因为每个节点必定要建立起边
int n, m, k;
LL ans = 0;

int h[N<<1], tot = 0;
struct edge
{
    int v, next;
    LL c;
}e[M*5];
void addedge(int u, int v, LL c)
{
    e[++tot].v = v; e[tot].c = c;
    e[tot].next = h[u]; h[u] = tot;
}

LL cost[15];
LL bld[15][N];

int vis[N<<1];  //标记每个城市是否已经连通

struct node
{
    int u;
    LL dis; //要链接上所要花费的距离
    bool operator < (const node &x) const
    {
        return dis < x.dis;
    }
    bool operator > (const node &x) const
    {
        return dis > x.dis;
    }
};
priority_queue<node, vector<node>, greater<node> > q;

void solve(int s);

//乡镇好恶心……但是有四个点没有乡镇，直接当生成树做就好了，一共16pts
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
    {
        int u, v, c;
        scanf("%d%d%d",&u,&v,&c);
        addedge(u, v, c);
        addedge(v, u, c);
    }

    //除了城市之外，还有k个乡镇准备城市化改造，它们独立于原来的城市，可以改造也可以不改造
    for(int i = 1;i <= k;i++)
    {
        scanf("%lld",&cost[i]);
        for(int j = 1;j <= n;j++)
        {
            //addedge(j, i+n, c);
            scanf("%lld",&bld[i][j]);
            addedge(j+n, j, cost[i]+bld[i][j]);
            addedge(j, j+n, cost[i]+bld[i][j]);
        }
    }

    solve(s);
    printf("%lld\n", ans);
    return 0;
}

void solve(int s)
{
    q.push({s, 0});
    while(!q.empty())
    {
        node tp = q.top();
        q.pop();
        int u = tp.u;
        if(vis[u]) continue;
        vis[u] = 1;
        //ans += tp.dis;
        ans += tp.dis;
        /*
        printf("->%d=%lld\n", u, tp.dis);
        if(u > n)
        {
            printf("ans=%lld\n achieve country %d\n",ans, u-n);
        }
        else
        {
            printf("achieve %d\n", u);
        }
        */

        for(int i = h[u];i;i = e[i].next)
        {
            int v = e[i].v;
            int c = e[i].c;
            if(!vis[v]) q.push({v, c});
        }
    }

}
