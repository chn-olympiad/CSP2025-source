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
   file(employ);
   cin.tie(nullptr)->sync_with_stdio(false);
   Solve();
}
const int P = 998244353;
const int N = 5e2+52;
int n,m;
int a[N],c[N];
void Solve() {
   cin>>n>>m;
   for(int i=0;i<n;i++) {
      char ch; cin>>ch; a[i]=ch=='1';
   }
   for(int i=0;i<n;i++) cin>>c[i];
   sort(c,c+n);
   // if(*min_element(s,s+n)==1) {
   //    return ;
   // }
   if(m==n) {
      if(*min_element(a,a+n)==1) return void(cout<<0<<endl);
      if(*min_element(c,c+n)==0) return void(cout<<0<<endl);
      ll ans=1;
      for(int i=1;i<=n;i++) ans=ans*i%P;
      cout<<ans<<endl;
      return ;
   }
   if(n<=18) {
      vv<ll> f(1<<n,vec<ll>(n+1));
      f[0][0]=1;
      for(int s=0;s<1<<n;s++) for(int k=0;k<=n;k++)
      if(f[s][k]) for(int i=0;i<n;i++) if(~s>>i&1) {
         int p=popcnt(s);
         (f[s|1<<i][k+(!a[p]||k>=c[i])]+=f[s][k])%=P;
      }
      ll ans=0;
      for(int k=0;k<=n-m;k++) ans+=f[(1<<n)-1][k];
      cout<<ans%P<<endl;
      return ;
   }
}