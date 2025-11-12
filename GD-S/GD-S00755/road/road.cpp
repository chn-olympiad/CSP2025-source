#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define ep emplace
#define pii pair<int,int>
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int maxn=1e4+10,maxm=1e6+10,maxk=15,maxp=maxn+maxk+10,maxK=(1<<10)+10;
bool mem1;
int n,m,k;
int a[maxk][maxn],c[maxk];
struct edge{int u,v,w;}E[maxm];
vector<edge> to[maxk];
// edge b[maxK][maxp];
vector<edge> b[maxK];
// int len[maxK];
ll f[maxK];
bool mem2;
inline bool cmp(edge x,edge y){return x.w<y.w;}
struct DSU{
    int fa[maxp];
    void init(){iota(fa+1,fa+n+k+1,1);}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    inline void merge(int x,int y){fa[find(x)]=find(y);}
}U;
vector<edge> kruskal(vector<edge> e,bool flag){
    if(flag)    sort(e.begin(),e.end(),cmp);
    vector<edge> ret;ret.clear();
    U.init();ll sum=0;
    for(int i=0;i<e.size();i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        u=U.find(u);v=U.find(v);
        if(u==v)    continue;
        U.merge(u,v);
        ret.eb(e[i]);sum+=e[i].w;
    }
    return ret;
}
vector<edge> my_merge(vector<edge> x,vector<edge> y){
    vector<edge> res;res.clear();
    int i=0,j=0;
    for(;i<x.size();i++){
        while(j<y.size()&&y[j].w<x[i].w)    res.eb(y[j]),j++;
        res.eb(x[i]);
    }
    while(j<y.size())   res.eb(y[j]),j++;
    return res;
}
inline int lowbit(int x){return x&-x;}
vector<edge> res;
int main(){
    double sta=clock();
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    debug("%.2fMB\n",abs(&mem1-&mem2)/1024./1024);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)   cin>>E[i].u>>E[i].v>>E[i].w;
    for(int i=1;i<=k;i++){
    	cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            to[i].eb((edge){i+n,j,a[i][j]});
        }
        sort(to[i].begin(),to[i].end(),cmp);
    }
    ll ans=0;
    {
        vector<edge> vE;vE.clear();for(int i=1;i<=m;i++)vE.eb(E[i]);
        vector<edge> res=kruskal(vE,1);
        for(int i=0;i<res.size();i++)   b[0].eb(res[i]),ans+=res[i].w;
    }
    for(int i=1;i<(1<<k);i++){
        int x=lowbit(i);
        x=__lg(x)+1;
        f[i]=f[i^lowbit(i)]+c[x];
        if(f[i]>=ans)    continue;
        res.clear();res=kruskal(my_merge(b[i^lowbit(i)],to[x]),0);
        ll sum=f[i];
        for(int j=0;j<res.size();j++)   b[i].eb(res[j]),sum+=res[j].w;
        ans=min(ans,sum);
    }
	cout<<ans;
    debug("%.0fms\n",(clock()-sta)/CLOCKS_PER_SEC*1000);
}