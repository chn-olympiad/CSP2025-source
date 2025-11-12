#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

using LL = long long;
using namespace std;

const int N = 2e5 + 10, M = 5e6 + 10, P = 998244353, base = 13331, base2 = 19260813;
string s[N][2], t[N][2];
int pre[2][M], pw[M];
int ans[N];

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  unordered_map<int, int> cnt, cnt1;
  pw[0] = 1;
  for (int i = 1; i < M; i++) {
    pw[i] = 1LL * pw[i - 1] * base % P;
  }
  int L1 = 0, L2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    L1 += sz(s[i][0]) * 2;
    int h0 = 0, h1 = 0;
    for (int j = 0; j < sz(s[i][0]); j++) {
      int w0 = s[i][0][j], w1 = s[i][1][j];
      h0 = (1LL * h0 * base + w0) % P;
      h1 = (1LL * h1 * base + w1) % P;
    }
    int h = (1LL * h0 * base2 + h1) % P;
    cnt[h]++;
    int p0 = 0, p1 = 0;
    for (int j = 0; j < sz(s[i][0]); j++) {
      if (s[i][0][j] == 'b') {
        p0 = j;
      }
      if (s[i][1][j] == 'b') {
        p1 = j;
      }
    }
    cnt1[p1 - p0]++;
  }
  for (int i = 1; i <= q; i++) {
    cin >> t[i][0] >> t[i][1];
    L2 += sz(t[i][0]) + sz(t[i][1]);
  }
  if (L2 <= 2000) {
    for (int i = 1; i <= q; i++) {
      if (sz(t[i][0]) != sz(t[i][1])) {
        cout << 0 << '\n';
        continue;
      }
      int len = sz(t[i][0]);
      int L = 0, R = len - 1;
      while (t[i][0][L] == t[i][1][L]) {
        L++;
      }
      while (t[i][0][R] == t[i][1][R]) {
        R--;
      }
      pre[0][0] = t[i][0][0];
      pre[1][0] = t[i][1][0];
      for (int j = 1; j < len; j++) {
        int w0 = t[i][0][j], w1 = t[i][1][j];
        pre[0][j] = (1LL * pre[0][j - 1] * base + w0) % P;
        pre[1][j] = (1LL * pre[1][j - 1] * base + w1) % P;
      }
      auto get = [&](int o, int l, int r) -> int {
        if (!l) {
          return pre[o][r];
        }
        return (pre[o][r] - 1LL * pre[o][l - 1] * pw[r - l + 1] % P + P) % P; 
      };
      int ans = 0;
      for (int l = 0; l <= L; l++) {
        for (int r = max(R, l); r < len; r++) {
          int w0 = get(0, l, r), w1 = get(1, l, r);
          int w = (1LL * w0 * base2 + w1) % P;
          ans += cnt[w];
        }
      }
      cout << ans << "\n";
    }
  }
  else {
    for (int i = 1; i <= q; i++) {
      if (sz(t[i][0]) != sz(t[i][1])) {
        cout << 0 << '\n';
        continue;
      }
      int p0 = 0, p1 = 0;
      for (int j = 0; j < sz(t[i][0]); j++) {
        if (t[i][0][j] == 'b') {
          p0 = j;
        }
        if (t[i][1][j] == 'b') {
          p1 = j;
        }
      }
      cout << cnt1[p1 - p0] << '\n';
    }
  }
  return 0;
}