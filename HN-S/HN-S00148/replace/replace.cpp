#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5 + 7;

int n, q, ans;
string s1[kN], s2[kN], t1, t2;

bool C(string a, string b, string c, string d) {
  int asz = a.size(), csz = c.size();
  if (asz < csz) return 0;
  string tmp = "";
  for (int i = 0; i < asz - csz + 1; i++) {
    if (a.substr(i, csz) == c) {
      tmp = "";
      for (int j = 0; j < i; j++) tmp += a[j];
      tmp += d;
      for (int j = i + csz; j < asz; j++) tmp += a[j];
      if (tmp == b) return 1;
    }
  }
  return 0;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> t1 >> t2, ans = 0;
    t1 = t1, t2 = t2;
    for (int j = 1; j <= n; j++) {
      ans += C(t1, t2, s1[j], s2[j]);
    }
    cout << ans << '\n';
  }

  return 0;
}
