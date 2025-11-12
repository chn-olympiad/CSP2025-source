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
  const int N=2e5+2,L=5e6+2,B[2]={131,1331},M[2]={1000000007,1000000009};
  int n,q,ans,ll,bs[2][L],sz[N];
  pii ns[N][2];
  string s[N][2],t[2];
  map<pii,map<pii,int> > mp;
  
  void Init () {
    bs[0][0]=1; for (int i=1;i<N;i++) bs[0][i]=bs[0][i-1]*B[0]%M[0];
    bs[1][0]=1; for (int i=1;i<N;i++) bs[1][i]=bs[1][i-1]*B[1]%M[1];
  }
  
  class HasH {
    public:
    int n,hs[2][L]; string s;
    void init (string _s) {
      s=_s,n=s.size ();
      hs[0][0]=0; for (int i=1;i<=n;i++) hs[0][i]=(hs[0][i-1]*B[0]+s[i-1])%M[0];
      hs[1][0]=0; for (int i=1;i<=n;i++) hs[1][i]=(hs[1][i-1]*B[1]+s[i-1])%M[1];
    }
    pii get (int l,int r) {
      if (l>r) return {-1,-1};
      pii rs;
      rs.fi=(hs[0][r]-hs[0][l-1]*bs[0][r-l+1]%M[0]+M[0])%M[0];
      rs.se=(hs[1][r]-hs[1][l-1]*bs[1][r-l+1]%M[1]+M[1])%M[1];
      return rs;
    }
  } hsh[2];
  
  pii get_hash (string s) {
    int n=s.size (); pii rs;
    rs.fi=0; for (int i=1;i<=n;i++) rs.fi=(rs.fi*B[0]+s[i-1])%M[0];
    rs.se=0; for (int i=1;i<=n;i++) rs.se=(rs.se*B[1]+s[i-1])%M[1];
    return rs;
  } 

  void Work (int _Qn) {
    cin>> t[0]>> t[1],ans=0,ll=min (t[0].size (),t[1].size ());
    if (ll!=t[0].size ()||ll!=t[1].size ()) return cout<< "0\n",void ();
    hsh[0].init (t[0]),hsh[1].init (t[1]);
    for (int l=1;l<=ll;l++) {
      if (hsh[0].get (1,l-1)!=hsh[1].get (1,l-1)) break;
      for (int r=ll;r>=l;r--) {
        if (hsh[0].get (r+1,ll)!=hsh[1].get (r+1,ll)) break;
        pii hp=hsh[0].get (l,r),hq=hsh[1].get (l,r);
        if (!mp.count (hp)) continue;
        if (!mp[hp].count (hq)) continue;
        ans+=mp[hp][hq];
      }
    } cout<< ans<< "\n";
  }

  void Solve (int _Tn) {
    cin>> n>> q;
    for (int i=1;i<=n;i++) {
      cin>> s[i][0],ns[i][0]=get_hash (s[i][0]);
      cin>> s[i][1],ns[i][1]=get_hash (s[i][1]);
      mp[ns[i][0]][ns[i][1]]++,sz[i]=min (s[i][0].size (),s[i][1].size ());
    }
    for (int _Qn=1;_Qn<=q;_Qn++) Work (_Qn);
  }

  int Main (int T=1,int _Tn=1) { for (Init ();_Tn<=T;_Tn++) Solve (_Tn); return 0; }
}

signed main () {
  freopen ("replace.in","r",stdin);
  freopen ("replace.out","w",stdout);
  return Lab::Main ();
}

/*
 * Author: M_CI
 * UID: 556851
 * Ciallo~
 */

