#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N=1e4+10,M=2.2e6+10;

int n,m,k;
ll totw;
int f[N];

int c[15];
int cost[15][N];

int id;
int mc[N][2];

struct edge{
    int u,v,w;
    bool operator<(const edge &b)const
    { return w<b.w; }
}e[M];

vector<edge> te;

int v[M],w[M],fi[N],ne[M];
int idx=1;

void add(int x,int y,int z)
{
    v[idx]=y,w[idx]=z;
    ne[idx]=fi[x];
    fi[x]=idx++;
}

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

void kruskal()
{
    sort(e+1,e+1+m);
    for(int i=1; i<=n; i++) f[i]=i;
    for(int i=1; i<=m; i++)
    {
        int a=find(e[i].u);
        int b=find(e[i].v);
        if(a==b) continue;
        f[b]=a;
        totw+=e[i].w;

        add(e[i].u,e[i].v,e[i].w);
        add(e[i].v,e[i].u,e[i].w);
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>k;

    for(int i=1; i<=m; i++) cin>>e[i].u>>e[i].v>>e[i].w;

    kruskal();

    for(int i=1; i<=k; i++)
    {
        cin>>c[i];
        for(int j=1; j<=n; j++) cin>>cost[i][j];
    }

    cout<<totw<<"\n";

    return 0;
}