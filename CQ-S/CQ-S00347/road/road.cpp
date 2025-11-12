//16:18 80+
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
using ll=long long;
const int N=1e4+5,M=1e6+5;
bool st;
template<int sz> struct DSU{
    int fa[sz];
    void clear(int x){for(int i=1;i<=x;i++) fa[i]=i;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y){fa[find(x)]=find(y);}
};
DSU<N+100>dsu;
struct edge{int u,v,w;};
bool cmp(edge x,edge y){return x.w<y.w;}
struct Edge{int u,v,w,in;};
bool cmp2(Edge x,Edge y){return x.w<y.w;}
vector<edge>E;
vector<Edge>VE;
ll n,m,k,c[15],a[15][N],num[15],val[15],ans;
ll Kruskal(int n){
    // make sure E is sorted
    dsu.clear(n);
    ll ret=0,cnt=0;
    for(auto it:E){
        if(!dsu.same(it.u,it.v)){
            ret+=it.w;dsu.merge(it.u,it.v);cnt++;
            // cerr<<it.u<<" "<<it.v<<" "<<it.w<<"\n";
            VE.push_back({it.u,it.v,it.w,-1});
        }
        if(cnt==n-1)    break;
    }
    // cerr<<"\n";
    return ret;
}
ll Kruskal2(int n,int ned,int op){
    dsu.clear(n);
    ll ret=0,cnt=0;
    for(auto it:VE){
        if(it.in!=-1&&!(op&(1<<it.in))) continue;
        if(!dsu.same(it.u,it.v)){
            ret+=it.w,dsu.merge(it.u,it.v),cnt++;
            // if(it.u>n)  num[it.u-n]++,val[it.u-n]=it.w;
        }
        if(cnt==ned-1)  return ret;
    }
    return ret;
}
bool ed;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cerr<<fixed<<setprecision(6)<<(&ed-&st)/1024.0/1024.0<<"MB\n";
    double st=clock();
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,E.push_back({u,v,w});
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
    sort(E.begin(),E.end(),cmp);
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
    ans=Kruskal(n);
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
    // cerr<<ans<<"\n";
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)   cin>>a[i][j],VE.push_back((Edge){n+i,j,a[i][j],i-1});
    }
    sort(VE.begin(),VE.end(),cmp2);
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
    for(int i=0;i<(1<<k);i++){
        ll tmpv=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))    tmpv+=c[j+1];
        }
        ans=min(ans,Kruskal2(n+k,n+__builtin_popcount(i),i)+tmpv);
    }
    // ans=Kruskal2(n+k,n+k,(1<<k)-1);
    // for(int i=1;i<=k;i++){
    //     if(num[i]==1)   ans-=val[i];
    //     else    ans+=c[i];
    // }
    cout<<ans<<"\n";
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
}