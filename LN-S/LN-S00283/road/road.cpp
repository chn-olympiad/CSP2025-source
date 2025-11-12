#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using ll = long long;
using pll = pair<ll, ll>;
constexpr int MAX_N=10000, MAX_M=1000000;

struct line
{
    int u;
    int v;
    ll weight;
}now[MAX_M+MAX_N*10+20], in[MAX_M+MAX_N*10+20];

int n, m, k;
int c[20], ar[20][MAX_N+10];
ll ans=INT_MAX;

int u, v, w;

int fa[MAX_N+30];
int find(int i)
{
    if(fa[i]==i)
    {
        return i;
    }
    fa[i]=find(fa[i]);
    return fa[i];
}

void dfs(int i, int m, int cost);
ll kruskal(int m);

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        in[i]={u, v, w};
    }

    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>ar[i][j];
        }
    }

    dfs(1, m, 0);
    cout<<ans<<endl<<std::flush;

    return 0;
}


void dfs(int i, int m, int cost)
{
    if(i>=k+1)
    {
        for(int j=0;j<m;j++)
        {
            now[j]=in[j];
        }
        ans=std::min(ans, kruskal(m)+cost);
        return;
    }
    dfs(i+1, m, cost);
    for(int j=1;j<=n;j++)
    {
        in[m+j]={n+i, j, ar[i][j]};
    }
    dfs(i+1, m+n, cost+c[i]);
}
ll kruskal(int m)
{
    ll ans=0;
    std::sort(now, now+m, [](line a, line b){return a.weight<b.weight;});
    for(int i=0;i<=n+k+10;i++)
    {
        fa[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        if(find(now[i].u)!=find(now[i].v))
        {
            fa[find(now[i].u)]=fa[now[i].v];
            ans+=now[i].weight;
        }
    }
    return ans;
}
