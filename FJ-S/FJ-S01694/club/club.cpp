#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;
int n, a[N], b[N], c[N];
set<pair<int, int>> ab, ac, ba, bc, ca, cb;

void solve() {
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  
  ab.clear(), ac.clear(), ba.clear(), bc.clear(), ca.clear(), cb.clear();
  
  int ar = 0, br = 0, cr = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    int mx = max({a[i], b[i], c[i]});
    if (mx == a[i]) {
//      cerr << i << ": choose a " << a[i] << ", to b -" << a[i] - b[i] << ", to c -" << a[i] - c[i] << '\n';
      
      ar++, res += a[i];
      ab.emplace(a[i] - b[i], i);
      ac.emplace(a[i] - c[i], i);
      
      if (ar > n / 2) {
        int bv = ab.begin()->first, bj = ab.begin()->second;
        int cv = ac.begin()->first, cj = ac.begin()->second;
        
        ar--;
        if (bv < cv && br < n / 2) {
//          cerr << bj << " from a to b, -" << bv << '\n';
          
          br++, res -= bv;
          ab.erase(ab.begin());
          ac.erase({a[bj] - c[bj], bj});
          ba.emplace(b[bj] - a[bj], bj);
          bc.emplace(b[bj] - c[bj], bj);
        }
        else {
//          cerr << cj << " from a to c, -" << cv << '\n';
          cr++, res -= cv;
          ab.erase({a[cj] - b[cj], cj});
          ac.erase(ac.begin());
          ca.emplace(c[cj] - a[cj], cj);
          cb.emplace(c[cj] - b[cj], cj);
        }
      }
    }
    else if (mx == b[i]) {
//      cerr << i << ": choose b " << b[i] << ", to a -" << b[i] - a[i] << ", to c -" << b[i] - c[i] << '\n';
      br++, res += b[i];
      ba.emplace(b[i] - a[i], i);
      bc.emplace(b[i] - c[i], i);
      
      if (br > n / 2) {
        int av = ba.begin()->first, aj = ba.begin()->second;
        int cv = bc.begin()->first, cj = bc.begin()->second;
        
        br--;
        if (av < cv && ar < n / 2) {
//          cerr << aj << " from b to a, -" << av << '\n';
          ar++, res -= av;
          ba.erase(ba.begin());
          bc.erase({b[aj] - c[aj], aj});
          ab.emplace(a[aj] - b[aj], aj);
          ac.emplace(a[aj] - c[aj], aj);
        }
        else {
//          cerr << cj << " from b to c, -" << cv << '\n';
          cr++, res -= cv;
          ba.erase({b[cj] - a[cj], cj});
          bc.erase(bc.begin());
          ca.emplace(c[cj] - a[cj], cj);
          cb.emplace(c[cj] - b[cj], cj);
        }
      }
    }
    else {
//      cerr << i << ": choose c " << c[i] << ", to a -" << c[i] - a[i] << ", to b -" << c[i] - b[i] << '\n';
      cr++, res += c[i];
      ca.emplace(c[i] - a[i], i);
      cb.emplace(c[i] - b[i], i);
      
      if (cr > n / 2) {
        int av = ca.begin()->first, aj = ca.begin()->second;
        int bv = cb.begin()->first, bj = cb.begin()->second;
        
        cr--;
        if (av < bv && ar < n / 2) {
//          cerr << aj << " from c to a, -" << av << '\n';
          ar++, res -= av;
          ca.erase(ca.begin());
          cb.erase({c[aj] - b[aj], aj});
          ab.emplace(a[aj] - b[aj], aj);
          ac.emplace(a[aj] - c[aj], aj);
        }
        else {
//          cerr << bj << " from c to b, -" << bv << '\n';
          br++, res -= bv;
          ca.erase({c[bj] - a[bj], bj});
          cb.erase(cb.begin());
          ba.emplace(b[bj] - a[bj], bj);
          bc.emplace(b[bj] - c[bj], bj);
        }
      }
    }
    
//    cerr << "ab: ";
//    for (auto p : ab) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
//    cerr << "ac: ";
//    for (auto p : ac) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
//    cerr << "ba: ";
//    for (auto p : ba) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
//    cerr << "bc: ";
//    for (auto p : bc) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
//    cerr << "ca: ";
//    for (auto p : ca) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
//    cerr << "cb: ";
//    for (auto p : cb) cerr << '(' << p.first << ' ' << p.second << ") ";
//    cerr << '\n';
  }
  
  cout << res << '\n';
//  cerr << '\n';
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int T;
  cin >> T;
  
  while (T--) solve();
}
