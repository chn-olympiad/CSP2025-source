#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=1e4+20;
int n,m,k,p;
int a[12][Maxn];
struct Graph
{
    struct Edge
    {
        int u,v,w;
        Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w) {}
        bool operator<(Edge b)
        {
            return w<b.w;
        }
    };
    int ans;
    int f[Maxn],d[Maxn];
    vector<Edge>edge;
    int find(int x)
    {
        if(f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    // bool cmp(Edge x,Edge y) {return x.w<y.w;}
    void merge(int x,int y) {f[find(x)]=find(y);}
    bool check(int x,int y) {return find(x)==find(y);}
    void add(int u,int v,int w) {edge.push_back(Edge(u,v,w));}
    void kru();
    void output()
    {
        cout<<ans<<endl;
        for(int i=0;i<edge.size();i++) cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
        cout<<endl;
    }
}g[2];
int dp[2];
int c[12];
int del[Maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[p].add(u,v,w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    g[p].kru();
    for(int i=1;i<=k;i++)
    {
        Graph tmp;
        tmp.edge=g[p].edge;
        for(int j=1;j<=n;j++) tmp.add(n+i,j,a[i][j]);
        tmp.kru();
        // tmp.output();
        if(tmp.ans+dp[p]+c[i]<g[p].ans+dp[p])
        {
            dp[p^1]=c[i]+dp[p];
            g[p^1].edge=tmp.edge;
            g[p^1].ans=tmp.ans;
            for(int j=n+1;j<=n+k;j++) if(del[j]) dp[p^1]-=c[j-n],del[j]=0;
            p^=1;
        }
        // g[p].output();
    }
    cout<<g[p].ans+dp[p]<<endl;
    return 0;
}
void Graph::kru()
{
    vector<Edge>re;
    ans=0;
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n+10;i++) f[i]=i,d[i]=0;
    for(int i=0;i<edge.size();i++)
    {
        if(check(edge[i].u,edge[i].v)) continue;
        merge(edge[i].u,edge[i].v);
        d[edge[i].u]++; d[edge[i].v]++;
        re.push_back(edge[i]);
    }
    edge.clear();
    // for(int i=1;i<=n+k;i++) cout<<d[i]<<" ";cout<<endl;
    for(int i=0;i<re.size();i++)
    {
        // cout<<re[i].u<<" "<<re[i].v<<endl;
        if(re[i].u>n && d[re[i].u]==1)
        {
            del[re[i].u]=1;
            continue;
        }
        if(re[i].v>n && d[re[i].v]==1)
        {
            del[re[i].v]=1;
            continue;
        }
        // cout<<"add!"<<endl;
        edge.push_back(re[i]);
        ans+=re[i].w;
    }
}