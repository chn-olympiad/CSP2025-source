#include <bits/stdc++.h>
using namespace std;

int n, q;
string s1[200020], s2[200020], t1, t2;

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
  }
  for(; q--; ) {
    cin >> t1 >> t2;
    if(t1.size() != t2.size()) {
      cout << 0 << '\n';
      continue;
    }
    int lp = -1, rp = -1, l = t1.size();
    for(int p = 0; p < l; p++) {
      if(t1[p] != t2[p]) {
        if(lp == -1) lp = p;
        rp = p;
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < l; j++) {
        if(j + s1[i].size() <= l && t1.substr(j, s1[i].size()) == s1[i] && t2.substr(j, s2[i].size()) == s2[i] && j <= lp && j + s1[i].size() > rp) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
