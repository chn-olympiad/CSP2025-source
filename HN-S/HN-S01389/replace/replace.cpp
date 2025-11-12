#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int kMaxN = 3030;

ll n, q, ans;
string s1[kMaxN], s2[kMaxN];

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++ i) {
    cin >> s1[i] >> s2[i];
  }
  if (n > 1000) {
    for (; q; -- q) {
      cout << "0\n";
    }
    return 0;
  }
  for (string t1, t2; q; -- q) {
    cin >> t1 >> t2, ans = 0;
    for (int i = 1; i <= n; ++ i) {
      if (t1.find(s1[i]) != t1.npos) {
        ll pos = t1.find(s1[i]);
        if (t1.substr(0, pos) + s2[i] + (pos + (int)s1[i].size() + 1 > t1.size()? "" : t1.substr(pos + (int)s1[i].size())) == t2) {
          ++ ans;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0; 
} 

