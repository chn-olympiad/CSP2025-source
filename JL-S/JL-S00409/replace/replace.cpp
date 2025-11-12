#include <bits/stdc++.h>


namespace daiari {
  using ll = long long;
  const int maxn = 2e5 + 5, maxm = 5e6 + 5;
  const ll base = 137, mod = 998444353;

  int n, q;
  int pwr[maxm];

  struct Str {
    ll val; int len;
    friend Str operator+ (const Str &a, const Str &b) {
      return { (a.val * pwr[b.len] + b.len) % mod, a.len + b.len };
    }
    friend Str operator+ (const Str &a, const char &b) {
      return { (a.val * base + b) % mod, a.len + 1 };
    }
    friend bool operator== (const Str &a, const Str &b) {
      return a.val == b.val && a.len == b.len;
    }
  };
  struct Strs {
    std::vector<Str> a;
    void build(const std::string &s) {
      a.clear();
      a.push_back({ 0, 0 });
      for (std::size_t i = 0; i < s.size(); ++i)
        a.push_back(a.back() + s[i]);
    }
    Str substr(int l, int r) const {
      return { (a[r + 1].val - a[l].val * pwr[r - l + 1] % mod + mod) % mod, r - l + 1 };
    }
  } s[maxn][2], t[maxn][2];
  struct Stat {
    Str core[2]; int span_l, span_r, center_l, center_r;
    void build(const std::string &s1, const std::string &s2, const Strs &S1, const Strs &S2) {
      if (s1 == s2) span_l = span_r = -1; // because t1 != t2, if s1 = s2 it's useless
      else {
        std::size_t i = 0, j = s1.size() - 1;
        while (s1[i] == s2[i]) ++i;
        while (s1[j] == s2[j]) --j;
        core[0] = S1.substr(i, j);
        core[1] = S2.substr(i, j);
        span_l = i, span_r = s1.size() - 1 - j;
        center_l = i, center_r = j;
      }
    }
  } a[maxn], b[maxn];

  struct Node {
    int span_l, span_r, center_l, center_r; Str val;
  };
  std::unordered_map<ll, std::vector<Node>> mp;

  namespace bruteforce_up {
    bool check() {
      return 1ll * n * q <= 100000000ll;
    }
    void solve() {
      for (int j = 1; j <= n; ++j) {
        ll hsh = a[j].core[0].val * mod + a[j].core[1].val;
        mp[hsh].push_back({ a[j].span_l, a[j].span_r, a[j].center_l, a[j].center_r, s[j][0].a.back() });
      }
      for (int i = 1; i <= q; ++i) {
        if (t[i][0].a.back().len != t[i][1].a.back().len) {
          std::cout << 0 << '\n';
          continue;
        }
        ll hsh = b[i].core[0].val * mod + b[i].core[1].val;
        if (!mp.count(hsh)) {
          std::cout << 0 << '\n';
          continue;
        }
        int res = 0;
        for (const auto &v : mp[hsh]) {
          int l = b[i].center_l - v.span_l, r = b[i].center_r + v.span_r;
          if (l < 0 || r >= t[i][0].a.back().len) continue;
          if (t[i][0].substr(l, r) == v.val) ++res;
        }
        std::cout << res << '\n';
      }
    }
  }
  namespace bruteforce {
    bool check() {
      return 1ll * n * q <= 100000000ll;
    }
    void solve() {
      for (int i = 1; i <= q; ++i) {
        if (t[i][0].a.back().len != t[i][1].a.back().len) {
          std::cout << 0 << '\n';
          continue;
        }
        int res = 0;
        for (int j = 1; j <= n; ++j) {
          if (b[i].core[0] == a[j].core[0] && b[i].core[1] == a[j].core[1]) {
            int l = b[i].center_l - a[j].span_l, r = b[i].center_r + a[j].span_r;
            if (l < 0 || r >= t[i][0].a.back().len) continue;
            if (t[i][0].substr(l, r) == s[j][0].a.back()) ++res;
          }
        }
        std::cout << res << '\n';
      }
    }
  }

#define S(x) if (x::check()) x::solve(); else
  int main() {
    pwr[0] = 1;
    for (int i = 1; i < maxm; ++i) pwr[i] = pwr[i - 1] * base % mod;

    std::cin >> n >> q;
    std::string _1, _2;
    for (int i = 1; i <= n; ++i) std::cin >> _1 >> _2, s[i][0].build(_1), s[i][1].build(_2), a[i].build(_1, _2, s[i][0], s[i][1]);
    for (int i = 1; i <= q; ++i) std::cin >> _1 >> _2, t[i][0].build(_1), t[i][1].build(_2), b[i].build(_1, _2, t[i][0], t[i][1]);

    S(bruteforce_up)
    bruteforce_up::solve();

    return 0;
  }
#undef S
}

int main() {
  using namespace std;
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  daiari::main();
  cout.flush();
  return 0;
}
