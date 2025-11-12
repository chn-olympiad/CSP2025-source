#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair

namespace Main {
  
  const int N=1e5+5;
  int n;
  int a[5];
  vector<int> Z[3];
  void Solve() {
    cin>>n;
    // cerr << n << '\n';
    ll ans=0;
    REP(i, 1, n) {
      cin>>a[0] >> a[1] >> a[2];
      pii mx={-1,-1},cmx={-1,-1};
      REP(j,0,2) {
        if(mp(a[j],j)>mx) cmx=mx,mx=mp(a[j],j);
        else cmx=max(cmx,mp(a[j],j));
      }
      ans+=mx.fi;
      Z[mx.se].push_back(cmx.fi-mx.fi);
    }
    // cerr<<ans<<'\n';
    REP(i,0,2) {
      if((int)Z[i].size()>n/2) {
        sort(Z[i].begin(),Z[i].end(),greater<int>());
        for(int z=0;z<=(int)Z[i].size()-n/2-1;z++) ans+=Z[i][z];
      }
    }
    cout<<ans<<'\n';

    REP(i,0,2) Z[i].clear();
  }
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		int cases;cin>>cases;
    // cerr << cases<<'\n';
    while(cases--)Solve();
		return 0;
	}
}

int main() {
#ifndef Ace
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	Main::main();
  // while(1);
	return 0;
} 
// Think TWICE, code ONCE
// Meb: 6mb