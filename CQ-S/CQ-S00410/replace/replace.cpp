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
   file(replace);
   cin.tie(nullptr)->sync_with_stdio(false);
   Solve();
}
const int P1=998244353,P2=1e9+9;
const int B1=131,B2=457;
const int N = 5e6+56;
ll pw1[N],pw2[N];
bool special(const string &s) {
   return count(ALL(s),'b')==1&&count(ALL(s),'a')+1==s.size();
}
vec<int> broden(const string &s) {
   vec<int> p(s.size()); p[0]=0;
   for(int i=1,j=0;i<s.size();i++) {
      while(j&&s[j]!=s[i]) j=p[j-1];
      if(s[j]==s[i]) ++j;
      p[i]=j;
   }
   return p;
}
void Solve() {
   pw1[0]=pw2[0]=1;
   for(int i=1;i<N;i++) {
      pw1[i]=pw1[i-1]*B1%P1;
      pw2[i]=pw2[i-1]*B2%P2;
   }
   auto hsh1 = [&](const vec<ll> &h,int l,int r) {
      return (h[r]-h[l]*pw1[r-l]%P1+P1)%P1;
   };
   auto hsh2 = [&](const vec<ll> &h,int l,int r) {
      return (h[r]-h[l]*pw2[r-l]%P2+P2)%P2;
   };
   vec<int> lens;
   int n,Q; cin>>n>>Q;
   map<pair<pair<int,int>,pair<int,int>>,int> mp;
   vec<string> us(n),ut(n);
   for(int i=0;i<n;i++) {
      string s,t; cin>>s>>t;
      lens.push_back(s.size());
      // ll s1=0,s2=0,t1=0,t2=0;
      // for(int i=0;i<s.size();i++) {
      //    s1=(s1*B1+s[i])%P1;
      //    s2=(s2*B2+s[i])%P2;
      // }
      // for(int i=0;i<t.size();i++) {
      //    t1=(t1*B1+t[i])%P1;
      //    t2=(t2*B2+t[i])%P2;
      // }
      // mp[{{s1,s2},{t1,t2}}]++;
      us[i]=move(s),ut[i]=move(t);
   }
   sort(ALL(lens)),lens.erase(unique(ALL(lens)),lens.end());
   vec<string> qs(Q),qt(Q); vec<ll> ans(Q);
   vv<ll> qhs1(Q),qhs2(Q),qht1(Q),qht2(Q);
   for(int T=0;T<Q;T++) [&]()->void {
      string s,t; cin>>s>>t;
      int m=s.size();
      vec<ll> hs1(m+1),hs2(m+1);
      vec<ll> ht1(m+1),ht2(m+1);
      for(int i=0;i<m;i++) {
         hs1[i+1]=(hs1[i]*B1+s[i])%P1;
         hs2[i+1]=(hs2[i]*B2+s[i])%P2;
         ht1[i+1]=(ht1[i]*B1+t[i])%P1;
         ht2[i+1]=(ht2[i]*B2+t[i])%P2;
      }
      // ll ans=0;
      // for(int len:lens) {
      //    for(int i=0;i+len<=m;i++) {
      //       pair<pair<int,int>,pair<int,int>> p;
      //       p={{hsh1(hs1,i,i+len),hsh2(hs2,i,i+len)},{hsh1(ht1,i,i+len),hsh2(ht2,i,i+len)}};
      //       if(hsh1(hs1,0,i)==hsh1(ht1,0,i)
      //        &&hsh2(hs2,0,i)==hsh2(ht2,0,i)
      //        &&hsh1(hs1,i+len,m)==hsh1(ht1,i+len,m)
      //        &&hsh2(hs2,i+len,m)==hsh2(hs2,i+len,m)
      //        &&mp.count(p)) ans+=mp[p];
      //    }
      // }
      // cout<<ans<<'\n';
      qs[T]=move(s),qt[T]=move(t);
      qhs1[T]=move(hs1);
      qhs2[T]=move(hs2);
      qht1[T]=move(ht1);
      qht2[T]=move(ht2);
   }();
   for(int T1=0;T1<n;T1++) {
      const string &vs=us[T1],&vt=ut[T1];
      auto ps=broden(vs),pt=broden(vt);
      for(int T2=0;T2<Q;T2++) {
         const auto &s=qs[T2],&t=qt[T2];
         if(s.size()!=t.size()) continue;
         int m=s.size();
         for(int i=0,js=0,jt=0;i<m;i++) {
            while(js&&vs[js]!=s[i]) js=ps[js-1];
            if(vs[js]==s[i]) ++js;
            while(jt&&vt[jt]!=t[i]) jt=pt[jt-1];
            if(vt[jt]==t[i]) ++jt;
            if(js==vs.size()&&jt==vt.size()) {
               if(hsh1(qhs1[T2],0,i-js+1)==hsh1(qht1[T2],0,i-js+1)
                &&hsh2(qhs2[T2],0,i-js+1)==hsh2(qht2[T2],0,i-js+1)
                &&hsh1(qhs1[T2],i+1,m)==hsh1(qht1[T2],i+1,m)
                &&hsh2(qhs2[T2],i+1,m)==hsh2(qhs2[T2],i+1,m)) ans[T2]++;
            }
            if(js==vs.size()) js=0;
            if(jt==vt.size()) jt=0;
         }
      }
   }
   for(int i=0;i<Q;i++) cout<<ans[i]<<'\n';
}