#include <bits/stdc++.h>

using namespace std;

namespace ZeroOf149 {

using ll = long long;

void read_it(int& num) {
  char ch;
  do ch = getchar();
  while (ch < '0' || ch > '9');
  num = 0;
  while ('0' <= ch && ch <= '9') {
    num = num * 10 + (ch ^ '0');
    ch = getchar();
  }
}

constexpr int N = 1e4 + 5, M = 1e6 + 5, K = 10 + 1;

// bool M_st;

struct DSU {
  void init(int n) {
    Q = 1;
    std::fill(tim + 1, tim + n + 1, 0);
  }
  
  void clear() { ++Q; }
  
  void reduce(int u) {
    if (tim[u] != Q) {
      tim[u] = Q;
      f[u] = u;
      s[u] = 1;
    }
  }
  
  int find(int u) {
    reduce(u);
    return u == f[u] ? u : f[u] = find(f[u]);
  }
  
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (s[u] < s[v]) std::swap(u, v);
    f[v] = u;
    s[u] += s[v];
    return true;
  }
  
  int f[N + K], s[N + K], Q, tim[N + K];
};

struct Eg {
  void get_it() {
    read_it(u);
    read_it(v);
    read_it(w);
  }
  
  int u, v, w;
} e[M], ee[M], tmp[M], ena[K][N];

bool operator<(Eg l, Eg r) { return l.w < r.w; }

int n, m, k, c[K];
DSU dsu;

// bool M_ed;

ll solve(int n, int m, bool fl = false) {
  ll ans = 0;
  dsu.clear();
  for (int i = 1, cnt = 0; cnt < n - 1 && i <= m; ++i) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (dsu.merge(u, v)) {
      ans += w;
      if (fl) e[++cnt] = e[i];
    }
  }
  return ans;
}

int my_main() {
  // fprintf(stderr, "!!! %.6lf MB !!!\n", (&M_st - &M_ed) / 1024. / 1024.);
  // auto T_st = clock();
  
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  
  read_it(n);
  read_it(m);
  read_it(k);
  for (int i = 1; i <= m; ++i) e[i].get_it();
  for (int i = 1; i <= k; ++i) {
    read_it(c[i]);
    for (int j = 1; j <= n; ++j) {
      int w;
      read_it(w);
      ena[i][j] = Eg{j, n + i, w};
    }
    std::sort(ena[i] + 1, ena[i] + n + 1);
  }
  dsu.init(n + k);
  std::sort(e + 1, e + m + 1);
  ll ans = solve(n, m, true);
  m = n - 1;
  std::copy(e + 1, e + m + 1, ee + 1);
  for (int b = 1; b < (1 << k); ++b) {
    std::copy(ee + 1, ee + m + 1, e + 1);
    int nn = n, mm = m;
    ll now = 0;
    for (int i = 1; i <= k; ++i) {
      if (!((b >> (i - 1)) & 1)) continue;
      ++nn;
      now += c[i];
      std::merge(e + 1, e + mm + 1, ena[i] + 1, ena[i] + n + 1, tmp + 1);
      mm += n;
      std::copy(tmp + 1, tmp + mm + 1, e + 1);
    }
    ans = std::min(ans, now + solve(nn, mm));
  }
  printf("%lld", ans);
  
  // auto T_ed = clock();
  // fprintf(stderr, "!!! %.6lf sec !!!\n", (T_ed - T_st) / 1000.);
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }
