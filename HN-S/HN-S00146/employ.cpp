#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define L128 __int128
#define pii pair<int,int>
#define fi first
#define se second

class IOS { public: IOS () { cin.tie (0)->sync_with_stdio (0); }} IOS;
template<typename T> T _Read () { T x; return cin>> x,x; }

namespace Lab {
  const int N=502;
  int n,m,ans,c[N],p[N];
  string s;
  
  namespace Sub1 {
    bool Check () { return n<=10; }
    void Solve () {
      iota (p+1,p+n+1,1),ans=0;
      do {
        int rs=0;
        for (int i=1,j=0;i<=n;i++)
          j<c[p[i]]&&(s[i-1]&15)? rs++: j++;
        ans+=(rs>=m);
      } while (next_permutation (p+1,p+n+1));
      cout<< ans<< "\n";
    }
  }

  void Solve (int _Tn) {
    cin>> n>> m>> s;
    for (int i=1;i<=n;i++) cin>> c[i];
    if (Sub1::Check ()) return Sub1::Solve ();
  }

  int Main (int T=1,int _Tn=1) { for (;_Tn<=T;_Tn++) Solve (_Tn); return 0; }
}

signed main () {
  freopen ("employ.in","r",stdin);
  freopen ("employ.out","w",stdout);
  return Lab::Main ();
}

/*
 * Author: M_CI
 * UID: 556851
 * Ciallo~
 */

