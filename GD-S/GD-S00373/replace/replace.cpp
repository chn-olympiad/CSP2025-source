#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int MOD = 1e9 + 7;

i64 power(i64 x, int p) {
  i64 res = 1;
  for (; p; p >>= 1) {
    if (p & 1) (res *= x) %= MOD;
    (x *= x) %= MOD;
  }
  return res;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);

  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<string> s1(n), s2(n);
  for (int i = 0; i < n; i++) {
    cin >> s1[i] >> s2[i];
    s1[i] = ' ' + s1[i];
    s2[i] = ' ' + s2[i];
  }

  vector<i64> h1(n), h2(n);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < (int)s1[i].size(); j++) {
      h1[i] = (h1[i] * 27 + s1[i][j] - 'a' + 1) % MOD;
      h2[i] = (h2[i] * 27 + s2[i][j] - 'a' + 1) % MOD;
    }
  }

  while (q--) {
    string t1, t2;
    cin >> t1 >> t2;
    t1 = ' ' + t1, t2 = ' ' + t2;
    int l = 1, r = (int)t1.size() - 1;
    while (l < (int)t1.size() && t1[l] == t2[l]) l++;
    while (r && t1[r] == t2[r]) r--;
    vector<i64> ht1(t1.size()), ht2(t1.size());
    for (int i = 1; i < (int)t1.size(); i++) {
      ht1[i] = (ht1[i - 1] * 27 + t1[i] - 'a' + 1) % MOD;
      ht2[i] = (ht2[i - 1] * 27 + t2[i] - 'a' + 1) % MOD;
    }
    i64 res = 0;
    for (int i = 0; i < n; i++) {
      int len = (int)s1[i].size() - 1;
      i64 P = power(27, len);
      for (int j = len; j < (int)t1.size(); j++) {
        if ((ht1[j] - ht1[j - len] * P % MOD + MOD) % MOD == h1[i]) {
          if ((ht2[j] - ht2[j - len] * P % MOD + MOD) % MOD == h2[i]) {
            if (j >= r && j - len + 1 <= l) res++;
          }
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
