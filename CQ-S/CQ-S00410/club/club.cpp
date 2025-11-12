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
   file(club);
   cin.tie(nullptr)->sync_with_stdio(false);
   int T; cin>>T; while(T--)
   Solve();
}
void Solve() {
   int n; cin>>n; int midn=n>>1;
   vec<array<int,3>> a(n);
   array<int,3> cnt{};
   for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
   ll ans=0;
   for(int i=0;i<n;i++) {
      int c=max_element(ALL(a[i]))-a[i].begin();
      ++cnt[c],ans+=a[i][c];
   }
   if(*max_element(ALL(cnt))<=midn)
      return void(cout<<ans<<'\n');
   int rt=max_element(ALL(cnt))-cnt.begin();
   for(int i=0;i<n;i++) {
      swap(a[i][0],a[i][rt]);
      Max(a[i][1],a[i][2]);
   }
   ans=0;
   min_heap<int> q;
   for(int i=0;i<n;i++) {
      ans+=a[i][0];
      q.emplace(a[i][0]-a[i][1]);
      if(q.size()>midn) ans-=q.top(),q.pop();
   }
   cout<<ans<<'\n';
}