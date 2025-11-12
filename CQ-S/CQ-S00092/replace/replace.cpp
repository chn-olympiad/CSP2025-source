#include <bits/stdc++.h>

using ull = unsigned long long;

constexpr int N = 4e5 + 10;
constexpr int L = 1e7 + 10;

int n, q;

int son[L][26], sont, vis[L];
int id[L], idtt, idt;

std::string s[N][2];
int sl[N], sr[N];

std::vector<int> si[N];

int ans[N];
int sid[N], sn;
int to[L];
int ed[N], pl[N][2], pr[N][2];

int dfn[L], rdfn[L], dn;
inline void dfs(int u) {
  dfn[u] = dn + 1, dn += vis[u];
  while (to[u]) {
    int i = __builtin_ctz(to[u]);
    dfs(son[u][i]);
    to[u] ^= 1 << i;
  }
  rdfn[u] = dn;
}

std::vector<std::tuple<int, int, int>> op;
int sum[N];
inline void add(int x, int y) {
  for (int i = x; i <= n + q; i += i & -i) {
    sum[i] += y;
  }
}
inline int qry(int x) {
  int y = 0;
  for (int i = x; i >= 1; i -= i & -i) {
    y += sum[i];
  }
  return y;
}

inline void solve() {
  auto clear = [&](int u) {
    vis[u] = 0;
    to[u] = 0;
  };
  auto find = [&](int u, int c) -> int& {
    if (~ to[u] >> c & 1) {
      son[u][c] = 0;
    }
    return son[u][c];
  };

  sont = 0, clear(0);
  for (int _i = 1; _i <= sn; _i++) {
    int i = sid[_i], u = 0;
    for (int j = sl[i] - 1; j >= 0; j--) {
      int &v = find(u, s[i][0][j] - 'a');
      if (! v) {
        clear(v = ++sont);
        to[u] |= 1 << s[i][0][j] - 'a';
      }
      u = v;
    }
    ed[i] = u, vis[u] = 1;
  }
  dn = 0, dfs(0);
  for (int _i = 1; _i <= sn; _i++) {
    int i = sid[_i];
    pl[i][0] = dfn[ed[i]], pr[i][0] = rdfn[ed[i]];
  }

  sont = 0, clear(0);
  for (int _i = 1; _i <= sn; _i++) {
    int i = sid[_i], u = 0;
    for (int j = sr[i] + 1; j < s[i][0].size(); j++) {
      int &v = find(u, s[i][0][j] - 'a');
      if (! v) {
        clear(v = ++sont);
        to[u] |= 1 << s[i][0][j] - 'a';
      }
      u = v;
    }
    ed[i] = u, vis[u] = 1;
  }
  dn = 0, dfs(0);
  for (int _i = 1; _i <= sn; _i++) {
    int i = sid[_i];
    pl[i][1] = dfn[ed[i]], pr[i][1] = rdfn[ed[i]];
  }

  op.clear();
  for (int _i = 1; _i <= sn; _i++) {
    int i = sid[_i];
    if (i <= n) {
      op.emplace_back(pl[i][0], 0, i);
      op.emplace_back(pr[i][0] + 1, 1, i);
    } else {
      op.emplace_back(pl[i][0], 2, i);
    }
  }
  std::sort(op.begin(), op.end());
  for (auto [_, o, i] : op) {
    if (o == 0) {
      add(pl[i][1], +1);
      add(pr[i][1] + 1, -1);
    } else if (o == 1) {
      add(pl[i][1], -1);
      add(pr[i][1] + 1, +1);
    } else {
      ans[i] = qry(pl[i][1]);
    }
  }
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> q;
  for (int i = 1; i <= n + q; i++) {
    std::cin >> s[i][0] >> s[i][1];
    if (s[i][0] == s[i][1] || s[i][0].size() != s[i][1].size()) {
      continue;
    }
    sl[i] = -1, sr[i] = 0;
    for (int j = 0; j < s[i][0].size(); j++) {
      if (s[i][0][j] != s[i][1][j]) {
        if (sl[i] == -1) {
          sl[i] = j;
        }
        sr[i] = j;
      }
    }
    int u = 0;
    for (int j = sl[i]; u != -1 && j <= sr[i]; j++) {
      int &v = son[u][s[i][0][j] - 'a'];
      if (i <= n) {
        u = v = ! v ? ++idtt : v;
      } else {
        u = v == 0 ? -1 : v;
      }
    }
    for (int j = sl[i]; u != -1 && j <= sr[i]; j++) {
      int &v = son[u][s[i][1][j] - 'a'];
      if (i <= n) {
        u = v = ! v ? ++idtt : v;
      } else {
        u = v == 0 ? -1 : v;
      }
    }
    if (i <= n) {
      id[u] = id[u] ? id[u] : ++idt;
      si[id[u]].push_back(i);
    } else {
      if (u != -1 && id[u]) {
        si[id[u]].push_back(i);
      }
    }
  }

  for (int t = 1; t <= idt; t++) {
    sn = 0;
    for (int u : si[t]) {
      sid[++sn] = u;
    }
    solve();
  }

  for (int i = n + 1; i <= n + q; i++) {
    std::cout << ans[i] << '\n';
  }

  return 0;
}