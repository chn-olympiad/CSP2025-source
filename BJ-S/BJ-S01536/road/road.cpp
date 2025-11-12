#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
const int maxn=1e4+20,maxk=10+1; const ll inf=1e18;
int n,m,k,fa[maxn],cost[maxn],sz[maxn]; ll ans=inf;
struct edge{
    int u,v,w;
    bool operator<(const edge other)const{ return w<other.w; }
}; vector<edge> edges,graph;
vector<edge> ai[maxk];

int get(int x){ return fa[x]==x?x:fa[x]=get(fa[x]); }
void bmerge(int x, int y){
    x=get(x); y=get(y);
    if(sz[x]>sz[y])swap(x,y);
    fa[x]=y; sz[y]+=sz[x];
}

vector<edge> mymerge(const vector<edge> a, const vector<edge>& b){
    auto p=a.begin(),q=b.begin(); vector<edge> res;
    while(p!=a.end()||q!=b.end()){
        if(q==b.end())res.push_back(*p),p++;
        else if(p==a.end())res.push_back(*q),q++;
        else if(*p<*q)res.push_back(*p),p++;
        else res.push_back(*q),q++;
    }
    return res;
}

int main(){
freopen("road.in", "r", stdin);
freopen("road.out", "w", stdout);
ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            ai[i].push_back({n+i,j,x});
        }
        sort(ai[i].begin(),ai[i].end());
    }
    sort(edges.begin(), edges.end());
    for(auto e:edges)if(get(e.u)!=get(e.v))bmerge(e.u,e.v),graph.push_back(e);
    for(int mask=0;mask<(1<<k);mask++){
        ll cur=0; vector<edge> newedges=graph;
        for(int i=0;i<k;i++)if((mask>>i)&1)cur+=cost[i+1],newedges=mymerge(newedges,ai[i+1]);
        if(cur>ans)continue;
        for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
        for(auto e:newedges)if(get(e.u)!=get(e.v)){
            bmerge(e.u,e.v);
            cur+=e.w;
            if(cur>ans)continue;
        }
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}