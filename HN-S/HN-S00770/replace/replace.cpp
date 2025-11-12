#include <bits/stdc++.h>

using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

constexpr int N = 2E5 + 5, L = 3.2E6 + 5;
std::mt19937_64 rng(20090627);
std::array<u64, N + N> w;
void Init() {
  for (int i = 0; i < N + N; ++i) w[i] = rng();
}

int n, q;
std::array<int, N> ans;
std::array<std::string, N> s1, s2;

std::array<int, N> lp, rp;
std::map<u64, std::vector<int>> rep;

int d, dt;
std::map<u64, int> rtl, rtr;
std::array<int, N> id;
std::array<int, L> dfn, low;
std::array<std::vector<int>, L> hg, qry;
std::array<std::array<int, 26>, L> to;
void Dfs(int o) {
  dfn[o] = ++dt;
  for (int v : to[o])
    if (v) Dfs(v);
  low[o] = dt;
}

std::array<int, N> qrp;
std::array<int, L> bit;
void Add(int x, int v) {
  for (; x <= d; x += x & -x) bit[x] += v;
}
int Query(int x) {
  int v = 0;
  for (; x; x &= x - 1) v += bit[x];
  return v;
}
void Proc(int o) {
  for (int i : hg[o]) Add(dfn[id[i]], 1), Add(low[id[i]] + 1, -1);
  for (int i : qry[o]) ans[i] = Query(dfn[qrp[i]]);
  for (int v : to[o])
    if (v) Proc(v);
  for (int i : hg[o]) Add(dfn[id[i]], -1), Add(low[id[i]] + 1, 1);
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Init();

  std::cin >> n >> q; 
  for (int i = 1; i <= n; ++i) std::cin >> s1[i] >> s2[i];
  
  for (int i = 1; i <= n; ++i) {
    if (s1[i] == s2[i]) continue;
    int m = s1[i].size(), l = m, r = 0;
    for (int p = 0; p < m; ++p)
      if (s1[i][p] - s2[i][p]) l = std::min(l, p), r = p;
    u64 h = 0;
    for (int j = l, p = 0; j <= r; ++j) {
      h ^= w[p++] * s1[i][j];
      if (s1[i][j] - s2[i][j]) h ^= w[p++] * (s2[i][j] + w[r - l]);
    }
    rep[h].push_back(i), lp[i] = l, rp[i] = r;
  }
  for (const auto &[h, vec] : rep) {
    rtl[h] = ++d, rtr[h] = ++d;
    for (int i : vec) {
      int u = rtl[h];
      for (int j = lp[i] - 1; ~j; --j) {
        if (!to[u][s1[i][j] - 'a']) to[u][s1[i][j] - 'a'] = ++d;
        u = to[u][s1[i][j] - 'a'];
      }
      hg[u].push_back(i), u = rtr[h];
      for (int j = rp[i] + 1; j < s1[i].size(); ++j) {
        if (!to[u][s1[i][j] - 'a']) to[u][s1[i][j] - 'a'] = ++d;
        u = to[u][s1[i][j] - 'a'];
      }
      id[i] = u;
    }
    dt = 0, Dfs(rtr[h]);
  }

  for (int i = 1; i <= q; ++i) {
    std::string t1, t2;
    std::cin >> t1 >> t2;
    int m = t1.size(), l = m, r = 0;
    for (int p = 0; p < m; ++p)
      if (t1[p] - t2[p]) l = std::min(l, p), r = p;
    u64 h = 0;
    for (int j = l, p = 0; j <= r; ++j) {
      h ^= w[p++] * t1[j];
      if (t1[j] - t2[j]) h ^= w[p++] * (t2[j] + w[r - l]);
    }
    if (rep.find(h) == end(rep)) continue;
    int u = rtl[h];
    for (int i = l - 1; ~i; --i)
      if (to[u][t1[i] - 'a'])
        u = to[u][t1[i] - 'a'];
      else
        break;
    qry[u].push_back(i), u = rtr[h];
    for (int i = r + 1; i < m; ++i)
      if (to[u][t1[i] - 'a'])
        u = to[u][t1[i] - 'a'];
      else
        break;
    qrp[i] = u;
  }

  for (const auto &[h, _] : rep) Proc(rtl[h]);

  for (int i = 1; i <= q; ++i) std::cout << ans[i] << '\n';

  return 0;
}