#include <bits/stdc++.h>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 5e6 + 5, kL = 26;

int id[kL][kL], cnt, n, m;
vector<int> a[kMaxN];
string s, t;

int main() {
  freopen("replace3.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      id[i][j] = cnt++;
    }
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s >> t;
    for (int j = 0; j < s.size(); j++) {
      a[i].push_back(id[s[j] - 'a'][t[j] - 'a']);
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> s >> t;
    int pl = -1, pr = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != t[j]) {
        (pl == -1) && (pl = j);
        pr = j;
      }
    }
    int ans = 0;
    for (int j = 0; j <= pl; j++) {
      for (int k = 1; k <= n; k++) {
        int to = j + a[k].size() - 1;
        if (to >= pr && to < s.size()) {
          bool v = 0;
          for (int l = j; l < j + a[k].size(); l++) {
            v |= a[k][l - j] != id[s[l] - 'a'][t[l] - 'a'];
          }
          ans += !v;
          if (!v) {
            break;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
// g++ baoli.cpp -o baoli -std=c++14 -O2 -Wall && ./baoli