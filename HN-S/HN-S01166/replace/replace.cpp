#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e3 + 100;
const int base = 1331;
const int mod = 19491001;

int n, q;
string s1[N], s2[N];

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
  }
  while (q--) {
    string t1, t2;
    int ans = 0;
    cin >> t1 >> t2;
    int num = 0;
    for (int i = 0; i < t1.size(); i++) {
      num += (t1[i] != t2[i]);
    }
    for (int i = 1; i <= n; i++) {
      if ((s1[i].size() != num || s1[i].size() != num) && (s1[i].size() != t1.size() || s2[i].size() != t2.size())) {
        continue;
      }
      bool f = 1;
      for (int j = 0; j < t1.size(); j++) {
        string b = "";
        for (int k = j; k < j + s1[i].size(); k++) {
          b += t1[k];
        }
        if (b == s1[i]) {
          b = "";
          for (int k = j; k < j + s2[i].size(); k++) {
            b += t2[k];
          }
          if (b == s2[i]) {
            ans++;
            f = 0;
            break;
          }
        }
        if (!f) {
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
