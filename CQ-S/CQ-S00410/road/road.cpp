#include<bits/stdc++.h>
#define file(F) freopen(#F".in","r",stdin),freopen(#F".out","w",stdout);
#define lowbit(x) ((x)&-(x))
#define popcnt(x) (__builtin_popcountll(x))
#define ALL(x) begin((x)),end((x))
namespace asnown {
using i32=int32_t; using u32=uint32_t;
using i64=int64_t; using u64=uint64_t;
using i128=__int128_t; using u128=__uint128_t;
template<typename T> using vec=std::vector<T>;
template<typename T> using vv=vec<vec<T>>;
template<typename T> using vvv=vec<vv<T>>;
template<typename T> using vvvv=vv<vv<T>>;
template<typename T> T abs(const T &x) { return x<0?-x:x; }
template<typename T> bool Max(T &x,const T &y) { return x<y&&(x=y,true); }
template<typename T> bool Min(T &x,const T &y) { return x>y&&(x=y,true); }
template<typename T> using max_heap=std::priority_queue<T>;
template<typename T> using min_heap=std::priority_queue<T,vec<T>,std::greater<>>;
u32 inverse(u32 a,u32 m) {
   u64 r=1; for(;a>1;a=m%a)
      r=(u64)r*(m-m/a)%m;
   return r;
}
} using namespace asnown;
using namespace std;
using ll=i64;
void Solve();
signed main() {
   file(road);
   cin.tie(nullptr)->sync_with_stdio(false);
   Solve();
}
const int N = 1e4+14;
int n,m,K;
vv<pair<int,int>> e;
int to[10],ww[10][N],cost[10];
int d[N],_d[N];
int fa[N];
void Solve() {
   int n,m,K; cin>>n>>m>>K;
   e.resize(n+K+1);
   for(int i=0;i<m;i++) {
      int u,v,w; cin>>u>>v>>w;
      e[u].push_back({v,w});
      e[v].push_back({u,w});
   }
   for(int k=0;k<K;k++) {
      cin>>cost[k];
      for(int i=1;i<=n;i++) cin>>ww[k][i];
      to[k]=min_element(ww[k]+1,ww[k]+n+1)-ww[k];
      if(!(ww[k][to[k]]+cost[k])) {
         for(int i=1;i<=n;i++) if(i!=to[k]) {
            e[to[k]].push_back({i,ww[k][i]});
            e[i].push_back({to[k],ww[k][i]});
         }
         k--,K--;
      } else {
         for(int i=1;i<=n;i++) e[n+k+1].push_back({i,ww[k][i]});
      }
   }
   fill(d+1,d+n+1,1e9);
   min_heap<tuple<int,int,int>> q;
   q.emplace(d[1]=0,1,fa[1]=0);
   while(!q.empty()) {
      auto [dis,u,ffa]=q.top(); q.pop();
      if(ffa!=fa[u]||dis!=d[u]) continue;
      for(auto [v,w]:e[u])
         if(v!=fa[u]&&Min(d[v],w))
            q.emplace(w,v,fa[v]=u);
   }
   ll ans=accumulate(d+1,d+n+1,(ll)0);
   memcpy(_d,d,sizeof d);
   for(int S=1;S<1<<K;S++) {
      fill(d+1,d+n+K+1,1e9);
      fill(fa+1,fa+n+K+1,0);
      min_heap<tuple<int,int,int>> q;
      ll res=0;
      for(int k=0;k<K;k++) if(S>>k&1) {
         res+=cost[k];
         for(int i=1;i<=n;i++) e[i].push_back({n+k+1,ww[k][i]});
      }
      q.emplace(d[1]=0,1,fa[1]=0);
      while(!q.empty()) {
         auto [dis,u,ffa]=q.top(); q.pop();
         if(ffa!=fa[u]||dis!=d[u]) continue;
         res+=d[u];
         for(auto [v,w]:e[u])
         if(v!=fa[u]&&Min(d[v],w))
         q.emplace(w,v,fa[v]=u);
      }
      Min(ans,res);
      for(int k=0;k<K;k++) if(S>>k&1)
         for(int i=1;i<=n;i++) e[i].pop_back();
   }
   cout<<ans<<endl;
}