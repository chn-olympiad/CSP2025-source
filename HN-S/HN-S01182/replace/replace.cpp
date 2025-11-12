#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

ifstream fin("replace.in");
ofstream fout("replace.out");

const int kMaxN = 2e5 + 1, kMaxL = 3e6 + 1, kB = 1000;
const int kBase[2] = {800000027, 800000153}, kMod[2] = {1000000021, 1000000207};

string s[kMaxN][2], t[2];
int n, q, n2, l, r, a[kMaxN][2][2], w[kMaxL][2];
vector<array<int, 2>> b[2];

void Calc(string &s, vector<array<int, 2>> &b) {
  b.clear();
  b.push_back({0, 0});
  for (int i = 0; i < s.size(); i++) {
    array<int, 2> bk = b.back();
    b.push_back({(1LL * bk[0] * kBase[0] + s[i]) % kMod[0], (1LL * bk[1] * kBase[1] + s[i]) % kMod[1]});
    // cout << s[i] << '\n';
    // cout << b.back()[0] << ' ' << b.back()[1] << '\n';
  }
}

bool F(int o, int l, int r, int i) {
  int v0 = (b[o][r][0] + kMod[0] - 1LL * b[o][l][0] * w[r - l][0] % kMod[0]) % kMod[0];
  int v1 = (b[o][r][1] + kMod[1] - 1LL * b[o][l][1] * w[r - l][1] % kMod[1]) % kMod[1];
  return v0 == a[i][o][0] && v1 == a[i][o][1];
}

int main() {
  w[0][0] = w[0][1] = 1;
  for (int i = 1; i < kMaxL; i++) {
    w[i][0] = 1LL * w[i - 1][0] * kBase[0] % kMod[0];
    w[i][1] = 1LL * w[i - 1][1] * kBase[1] % kMod[1];
  }
  fin >> n >> q;
  for (int i = 1, r = n + 1; i <= n; i++) {
    fin >> s[0][0] >> s[0][1];
    if (s[0][0].size() <= kB) {
      ++n2, s[n2][0] = s[0][0], s[n2][1] = s[0][1];
    } else {
      r--, s[r][0] = s[0][0], s[r][1] = s[0][1];
    }
  }
  for (int i = 1; i <= n; i++) {
    Calc(s[i][0], b[0]);
    a[i][0][0] = b[0].back()[0], a[i][0][1] = b[0].back()[1];
    Calc(s[i][1], b[1]);
    a[i][1][0] = b[1].back()[0], a[i][1][1] = b[1].back()[1];
    // cout << a[i][0][0] << ' ' << a[i][0][1] << ' ' << a[i][1][0] << ' ' << a[i][1][1] << '\n';
  }
  while (q--) {
    fin >> t[0] >> t[1];
    if (t[0].size() != t[1].size()) {
      fout << "0\n";
      continue;
    }
    for (l = 0; t[0][l] == t[1][l]; l++) {
    }
    for (r = t[0].size(); t[0][r] == t[1][r]; r--) {
    }
    Calc(t[0], b[0]), Calc(t[1], b[1]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = max(0, r - int(s[i][0].size()) + 1); j <= l && j + s[i][0].size() <= t[0].size(); j++) {
        ans += F(0, j, j + s[i][0].size(), i) && F(1, j, j + s[i][0].size(), i);
      }
    }
    fout << ans << '\n';
  }
  return 0;
}