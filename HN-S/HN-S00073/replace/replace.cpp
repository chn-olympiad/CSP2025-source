#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 2e5 + 5, D = 5e6, M = D + 5, B = 13331;
int n, q;
ull pw[M], H1[M], H2[M];
unordered_map<ull, int> z;
vector<pair<int, int>> p[M * 2];
string s[N][2], t[N][2];
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    int v = 0;
    for (char c : s[i][0]) c == 'b' ? v++ : f &= c == 'a';
    f &= v == 1, v = 0;
    for (char c : s[i][1]) c == 'b' ? v++ : f &= c == 'a'; 
    f &= v == 1;
  }
  for (int i = 1; i <= q; i++) {
    cin >> t[i][0] >> t[i][1];
    int v = 0;
    for (char c : t[i][0]) c == 'b' ? v++ : f &= c == 'a';
    f &= v == 1, v = 0;
    for (char c : t[i][1]) c == 'b' ? v++ : f &= c == 'a';
    f &= v == 1;
  }
  if (f) {
    for (int i = 1; i <= n; i++) {
      int p1, p2;
      for (int j = 0; j < s[i][0].size(); j++) s[i][0][j] == 'b' && (p1 = j);
      for (int j = 0; j < s[i][1].size(); j++) s[i][1][j] == 'b' && (p2 = j);
      p[p1 - p2 + D].push_back({p1, s[i][0].size() - p2});
    }
    for (int i = 1; i <= q; i++) {
      int p1, p2;
      for (int j = 0; j < t[i][0].size(); j++) t[i][0][j] == 'b' && (p1 = j);
      for (int j = 0; j < t[i][1].size(); j++) t[i][1][j] == 'b' && (p2 = j);
      int v = 0;
      for (pair<int, int> k : p[p1 - p2 + D])
        v += k.first <= p1 && k.second <= t[i][0].size() - p2;
      cout << v << "\n";
    }
  } else {
    for (int i = pw[0] = 1; i <= D; i++) pw[i] = pw[i - 1] * B;
    for (int i = 1; i <= n; i++) {
      ull h1 = 0, h2 = 0;
      for (char c : s[i][0]) h1 = h1 * B + c;
      for (char c : s[i][1]) h2 = h2 * B + c;
      z[(h1 * pw[s[i][0].size()] + '#') * B + h2]++;
//      cout << (h1 * pw[s[i][0].size()] + '#') * B + h2 << "\n";
    }
    for (int i = 1; i <= q; i++) {
      int m = t[i][0].size();
      t[i][0] = " " + t[i][0], t[i][1] = " " + t[i][1];
      for (int j = 1; j <= m; j++) H1[j] = H1[j - 1] * B + t[i][0][j];
      for (int j = 1; j <= m; j++) H2[j] = H2[j - 1] * B + t[i][1][j];
      int v = 0;
      for (int l = 1; l <= m; l++) {
        ull h1 = 0, h2 = 0;
        for (int r = l; r <= m; r++) {
          h1 = h1 * B + t[i][0][r];
          h2 = h2 * B + t[i][1][r];
//          cout << l << " " << r << " " << (h1 * pw[r - l + 1] + '#') * 13331 + h2 << " " << z[(h1 * pw[r - l + 1] + '#') * B + h2] << "\n";
          H1[l - 1] * pw[m - l + 1] + h2 * pw[m - r] + H1[m] - H1[r] * pw[m - r] == H2[m] && (v += z[(h1 * pw[r - l + 1] + '#') * B + h2]);
        }
      }
      cout << v << "\n";
    }
  } 
  return 0;
}
/*
看起来会写 50分，实际只写出了 25
努力尝试中 

终于写出 50分玄学做法，不知道能不能过 保佑我 
*/
