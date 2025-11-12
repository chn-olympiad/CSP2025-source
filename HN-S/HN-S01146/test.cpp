#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 2e5 + 1, kL = 5e6 + 1;
constexpr LL kP = LL(1e18) + 9, kB = 100003;

int n, q;
string s1, s2;
unordered_map<LL, vector<pair<int, LL>>> M[kL];
__int128 h[kL], b[kL];
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  b[0] = 1;
  for (int i = 1; i < kL; i++)
    b[i] = kB * b[i - 1] % kP;
  for (int i = 1; i <= n; i++) {
    cin >> s1 >> s2;
    int len = s1.size();
    s1 = '#' + s1, s2 = '#' + s2;
    if (s1 == s2)
      continue;
    int L = 0, R = 0;
    __int128 hsh = 0, all = 0;
    for (int i = 1; i <= len; i++) {
      if (s1[i] != s2[i])
        !L && (L = i), R = i;
      all = (kB * all + s1[i] * 133 + s2[i]) % kP;
    }
    for (int i = L; i <= R; i++)
      hsh = (kB * hsh + s1[i] * 133 + s2[i]) % kP;
    
    M[len - R][LL(hsh)].emplace_back(len, all);
  }
  for (; q--;) {
    cin >> s1 >> s2;
    int len = s1.size();
    s1 = '#' + s1, s2 = '#' + s2;
    int L = 0, R = 0;
    for (int i = 1; i <= len; i++) {
      if (s1[i] != s2[i])
        !L && (L = i), R = i;
      h[i] = (kB * h[i - 1] + s1[i] * 133 + s2[i]) % kP;
    }
    __int128 hsh = 0;
    for (int i = L; i <= R; i++)
      hsh = (kB * hsh + s1[i] * 133 + s2[i]) % kP;
    int ans = 0;
    for (int i = R; i <= len; i++) {
      if (!M[i - R].count(hsh))
        continue;
      for (auto P : M[i - R][hsh]) {
        int len = P.first;
        LL H = P.second;
        // cerr << len << ' ' << H << '\n';
        // cerr << LL((h[i] - h[i - len] * b[i - len] + kP) % kP) << ' ' << LL(H * b[i - len] % kP) << '\n';
        ans += ((h[i] - h[i - len] * b[len] % kP + kP) % kP == H);
      }
    }
    // cerr << '\n';
    cout << ans << '\n';
  }
  return 0;
}