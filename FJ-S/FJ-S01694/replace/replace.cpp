#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
string s[N], t[N];

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
  }
  
  while (q--) {
    string u, v;
    cin >> u >> v;
    
    if (u.size() != v.size()) {
      cout << 0 << '\n';
      continue;
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int pos = u.find(s[i]);
//      cout << u << ' ' << s[i] << ' ' << pos << '\n';
      
      if (pos != -1) {
        string u2 = u;
        for (int j = pos; j < pos + s[i].size(); j++)
          u2[j] = t[i][j - pos];
        
        if (u2 == v) res++;
      }
    }
    
    cout << res << '\n';
  }
}
