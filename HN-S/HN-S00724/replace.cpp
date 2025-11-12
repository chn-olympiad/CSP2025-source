#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

string s[N][4];
int hs[N][4];
basic_string<int> hz[N][4];
vector<int> hsh[N];

bool end_with(string a, string b) {
  if (a.size() < b.size()) {
    return 0;
  }
  for (int i = 1; i <= b.size(); i++) {
    if (a[a.size() - i] != b[b.size() - i]) {
      return 0;
    }
  }
  return 1;
}

bool start_with(string a, string b) {
  if (a.size() < b.size()) {
    return 0;
  }
  for (int i = 0; i < b.size(); i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][1] >> s[i][2];
    string a, b;
    int p = 0, q = s[i][1].size() - 1;
    while (p < s[i][1].size() && s[i][1][p] == s[i][2][p]) {
      s[i][0] += s[i][1][p];
      p++;
    }
    while (q >= 0 && s[i][1][q] == s[i][2][q]) {
      s[i][3] += s[i][1][q];
      q--;
    }
    reverse(s[i][3].begin(), s[i][3].end());
    while (p <= q) {
      a += s[i][1][p], b += s[i][2][p];
      p++;
    }
    s[i][1] = a, s[i][2] = b;
    int h = 0;
    for (char c : a) {
      h = (h * 19114517ll + c) % N;
    }
    for (char c : b) {
      h = (h * 19114517ll + c) % N;
    }
    hsh[h].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    string t1, t2, a, b, x, z;
    cin >> t1 >> t2;
    int p = 0, q = t1.size() - 1;
    while (p < t1.size() && t1[p] == t2[p]) {
      x += t1[p];
      p++;
    }
    while (q >= 0 && t1[q] == t2[q]) {
      z += t1[q];
      q--;
    }
    reverse(z.begin(), z.end());
    while (p <= q) {
      a += t1[p], b += t2[p];
      p++;
    }
    t1 = a, t2 = b;
    int ans = 0, h = 0;
    for (char c : a) {
      h = (h * 19114517ll + c) % N;
    }
    for (char c : b) {
      h = (h * 19114517ll + c) % N;
    }
    for (int j : hsh[h]) {
      if (s[j][1] == t1 && s[j][2] == t2 && end_with(x, s[j][0]) && start_with(z, s[j][3])) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}