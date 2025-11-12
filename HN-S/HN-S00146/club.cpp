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
  const int N=1e5+2;
  int n,ans,tmp[N],del[N],top[N];
  pii p[N][4];
  priority_queue<pii,vector<pii>,greater<pii> > q[3];
  
  void ins (int x) {
    q[p[x][top[x]].se].push ({p[x][top[x]].fi-p[x][top[x]+1].fi,x});
    tmp[x]=p[x][top[x]].fi;
  }

  void Solve (int _Tn) {
    cin>> n,ans=0;
    for (int i: {0,1,2}) for (;q[i].size ();q[i].pop ());
    for (int i=1;i<=n;i++) {
      for (int j: {0,1,2}) cin>> p[i][j].fi,p[i][j].se=j;
      sort (p[i],p[i]+3,greater<pii> ()),top[i]=0,ins (i);
    }
    while (1) {
      bool ch=0;
      for (int i: {0,1,2}) {
        for (int u;q[i].size ()+del[i]>(n>>1);) {
          assert (q[i].size ());
          u=q[i].top ().se,q[i].pop (),++top[u],ch=1;
          top[u]<3? ins (u): (del[i]++,void ());
        }
      }
      if (!ch) break;
    }
    for (int i=1;i<=n;i++) ans+=tmp[i];
    cout<< ans<< "\n";
  }

  int Main (int T=1,int _Tn=1) { for (;_Tn<=T;_Tn++) Solve (_Tn); return 0; }
}

signed main () {
  freopen ("club.in","r",stdin);
  freopen ("club.out","w",stdout);
  return Lab::Main (_Read<int> ());
}

/*
 * Author: M_CI
 * UID: 556851
 * Ciallo~
 */

