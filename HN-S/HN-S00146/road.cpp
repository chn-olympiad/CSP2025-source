#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define L128 __int128
#define int LL
#define pii pair<int,int>
#define fi first
#define se second

class IOS { public: IOS () { cin.tie (0)->sync_with_stdio (0); }} IOS;
template<typename T> T _Read () { T x; return cin>> x,x; }

namespace Lab {
  const int N=1e4+2,M=1e7+2,K=12;
  int n,m,k,g,ans,rs,c[K],a[K][N];
  
  class E {
    public: int u,v,w,k;
    E (int _u=0,int _v=0,int _w=0,int _k=0) { u=_u,v=_v,w=_w,k=_k; }
    bool operator < (const E &re) const { return w<re.w; }
  } e[M];
  
  class DSU {
    public:
    int n,f[N];
    void init (int _n) { n=_n,iota (f+1,f+n+1,1); }
    int find (int x) { return f[x]==x? x: f[x]=find (f[x]); }
    void merge (int x,int y) { if ((x=find (x))!=(y=find (y))) f[y]=x; }
  } dsu;
  
  namespace Sub1 {
    bool Check () { return n<=10000&&count (c+1,c+k+1,0)==k; }
    void Solve () {
      for (int u=1;u<n;u++) {
        for (int v=u+1;v<=n;v++) {
          int w=LLONG_MAX;
          for (int i=1;i<=k;i++) w=min (w,a[i][u]+a[i][v]);
          e[++g]={u,v,w};
        }
      }
      sort (e+1,e+g+1),ans=0,dsu.init (n);
      for (int i=1,j=0;i<=g,j<n-1;i++)
        if (dsu.find (e[i].u)!=dsu.find (e[i].v))
          ans+=e[i].w,dsu.merge (e[i].u,e[i].v),j++;
      cout<< ans<< "\n";
    }
  }
  
  namespace Sub2 {
    bool Check () { return (n<=10000&&k<=0)||(n<=1000&&k<=5); }
    void Solve () {
      for (int i=1;i<=k;i++)
        for (int u=1;u<n;u++)
          for (int v=u+1;v<=n;v++)
            e[++g]={u,v,a[i][u]+a[i][v]};
      sort (e+1,e+g+1),ans=LLONG_MAX;
      for (int S=0;S<1<<k;S++) {
        dsu.init (n),rs=0;
        for (int i=1;i<=k;i++) if ((S>>(i-1))&1) rs+=c[i];
        for (int i=1,j=0;i<=g&&j<n-1;i++) {
          if (e[i].k&&!((S>>(e[i].k-1))&1)) continue;
          if (dsu.find (e[i].u)!=dsu.find (e[i].v)) rs+=e[i].w,dsu.merge (e[i].u,e[i].v),j++;
        } ans=min (ans,rs);
      } cout<< ans<< "\n";
    }
  }

  void Solve (int _Tn) {
    cin>> n>> m>> k,g=0;
    for (int i=1,u,v,w;i<=m;i++) {
      cin>> u>> v>> w;
      if (u>v) swap (u,v); 
      e[++g]={u,v,w,0};
    }
    for (int i=1;i<=k;i++) {
      cin>> c[i];
      for (int v=1;v<=n;v++) cin>> a[i][v];
    }
    if (Sub1::Check ()) return Sub1::Solve ();
    if (Sub2::Check ()) return Sub2::Solve ();    
  }

  int Main (int T=1,int _Tn=1) { for (;_Tn<=T;_Tn++) Solve (_Tn); return 0; }
}

signed main () {
  freopen ("road.in","r",stdin);
  freopen ("road.out","w",stdout);
  return Lab::Main ();
}

/*
 * Author: M_CI
 * UID: 556851
 * Ciallo~
 */

