#include <bits/stdc++.h>
using namespace std;
#define INPUT_FILE "road.in"
#define OUTPUT_FILE "road.out"
using ll = long long;
constexpr int N=1e4+3;
constexpr int M=1e6+3;
constexpr int K=13;
int n,m,k,cost[K];
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &rhs)const
    {
        return w<rhs.w;
    }
} e[M];
struct DSU
{
    int fa[N];
    void init(int len)
    {
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    int find(int x)
    {
        if(fa[x]==fa[fa[x]]) return fa[x];
        while(fa[x]^x) x=fa[x]=fa[fa[x]];
        return x;
    }
} dsu;
vector<Edge> te,p[K];
void mymerge(const vector<Edge> &a,const vector<Edge> &b,vector<Edge> &c)
{
    int pos1=0,pos2=0,pos3=0;
    while(pos1<a.size()&&pos2<b.size())
        if(a[pos1]<b[pos2]) c[pos3++]=a[pos1++];
        else c[pos3++]=b[pos2++];
    while(pos1<a.size()) c[pos3++]=a[pos1++];
    while(pos2<b.size()) c[pos3++]=b[pos2++];
}
ll calc(int S)
{
    static vector<Edge> edge;
    edge=te;
    dsu.init(n+k);
    ll res=0;
    for(int i=S;i;i-=(i&-i))
    {
        static vector<Edge> tmp;
        const int pos=__builtin_ctz(i);
        res+=cost[pos];
        tmp.resize(edge.size()+p[pos].size());
        mymerge(edge,p[pos],tmp);
        swap(edge,tmp);
    }
    for(auto &&x:edge)
    {
        if(dsu.find(x.u)==dsu.find(x.v)) continue;
        res+=x.w;dsu.fa[dsu.find(x.u)]=dsu.find(x.v);
    }
    return res;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);dsu.init(n);
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        // printf("%d:%d %d:%d w:%d\n",e[i].u,dsu.find(e[i].u),e[i].v,dsu.find(e[i].v),e[i].w);
        if(dsu.find(e[i].u)==dsu.find(e[i].v)) continue;
        ans+=e[i].w;dsu.fa[dsu.find(e[i].u)]=dsu.find(e[i].v);
        te.push_back(e[i]);
    }
    for(int i=0;i<k;i++)
    {
        cin>>cost[i];
        p[i].resize(n);
        for(int j=0;j<n;j++)
        {
            cin>>p[i][j].w;
            p[i][j].u=i+n+1;
            p[i][j].v=j+1;
        }
        sort(p[i].begin(),p[i].end());
    }
    // printf("ans:%lld\n",ans);
    for(int i=0;i<1<<k;i++)
    {
        ll tmp=calc(i);
        // printf("calc(%d):%lld\n",i,tmp);
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
inline __attribute((constructor)) void init_io()
{
#ifdef INPUT_FILE
    freopen(INPUT_FILE,"r",stdin);
#endif
#ifdef OUTPUT_FILE
    freopen(OUTPUT_FILE,"w",stdout);
#endif
#ifndef RUN_ON_LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
#endif
}