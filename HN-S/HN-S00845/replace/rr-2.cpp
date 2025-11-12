// g++ -std=c++14 -O2 -fsanitize=address,undefined -o replace replace.cpp && ./replace
#include <bits/stdc++.h>

// #define int int64_t

using u64 = uint64_t;

const int kMaxN = 2e5 + 5, kMaxL = 5e6 + 5;

int n, q, id_tot;
int res[kMaxN];
int lcp_s[kMaxN], lcs_s[kMaxN], lcp_t[kMaxN], lcs_t[kMaxN];
int poss[kMaxN], post[kMaxN], ids[kMaxN], idt[kMaxN];
u64 hss[kMaxN], hst[kMaxN];
u64 pw[kMaxL];
std::string s1[kMaxN], s2[kMaxN], t1[kMaxN], t2[kMaxN];
std::vector<u64> hs_s1[kMaxN], hs_s2[kMaxN], hs_t1[kMaxN], hs_t2[kMaxN];

int trie_tot, trie[kMaxL][26], fail[kMaxL], cnt[kMaxL];
int dfn[kMaxL], sz[kMaxL];
std::unordered_map<u64, int> id;
std::vector<int> vec[kMaxL], G[kMaxL], pre[kMaxN];
std::vector<std::pair<int, int>> diff[kMaxN];

u64 gethash(std::vector<u64> &hs, int l, int r) {
  if (l > r) return 0;
  // std::cerr << "fuck " << l << ' ' << r << '\n';
  assert(1 <= l && l <= r && r < hs.size());
  return hs[r] - hs[l - 1] * pw[r - l + 1];
}

int getlcp(std::string &s, std::string &t) {
  int ret = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == t[i]) ++ret;
    else break;
  }
  return ret;
}

int getlcs(std::string &s, std::string &t) {
  int ret = 0;
  for (int i = (int)s.size() - 1; i; --i) {
    if (s[i] == t[i]) ++ret;
    else break;
  }
  return ret;
}

void prework(int n = 5e6) {
  pw[0] = 1;
  for (int i = 1; i <= 5e6; ++i) pw[i] = 13331ull * pw[i - 1];
}

void ins(std::string s) {
  int cur = 0;
  for (auto c : s) {
    int k = c - 'a';
    if (!trie[cur][k]) trie[cur][k] = ++trie_tot;
    cur = trie[cur][k];
  }
}

int getpos(std::string s) {
  int cur = 0;
  for (auto c : s) {
    int k = c - 'a';
    if (!trie[cur][k]) trie[cur][k] = ++trie_tot;
    cur = trie[cur][k];
  }
  return cur;
}

void dfs(int u) {
  static int dfn_cnt = 0;
  dfn[u] = ++dfn_cnt, sz[u] = 1;
  for (auto v : G[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

void build() {
  std::queue<int> q;
  for (int i = 0; i < 26; ++i)
    if (trie[0][i])
      q.emplace(trie[0][i]);
  for (; !q.empty();) {
    int u = q.front(); q.pop();
    for (int i = 0; i < 26; ++i) {
      if (trie[u][i]) {
        fail[trie[u][i]] = trie[fail[u]][i];
        q.emplace(trie[u][i]);
      } else {
        trie[u][i] = trie[fail[u]][i];
      }
    }
  }
  for (int i = 1; i <= trie_tot; ++i) G[fail[i]].emplace_back(i);
  dfs(0);
}

int getsum(std::vector<std::pair<int, int>> &diff, std::vector<int> &pre, int x) {
  if (!pre.size()) return 0;
  auto it = std::lower_bound(diff.begin(), diff.end(), std::pair<int, int>{x + 1, -2});
  int p = it - diff.begin();
  if (p == diff.size()) return pre.back();
  else return p ? pre[p - 1] : 0;
}

void dickdreamer() {
  std::cin >> n >> q;
  prework();
  for (int i = 1; i <= n; ++i) {
    std::cin >> s1[i] >> s2[i];
    s1[i] = " " + s1[i], s2[i] = " " + s2[i];
    assert(s1[i].size() == s2[i].size());
    hs_s1[i].resize(s1[i].size(), 0), hs_s2[i].resize(s2[i].size(), 0);
    for (int j = 1; j < s1[i].size(); ++j) {
      hs_s1[i][j] = 13331ull * hs_s1[i][j - 1] + s1[i][j];
      hs_s2[i][j] = 13331ull * hs_s2[i][j - 1] + s2[i][j];
    }
    lcp_s[i] = getlcp(s1[i], s2[i]), lcs_s[i] = getlcs(s1[i], s2[i]);
    if (lcp_s[i] + lcs_s[i] > s1[i].size() - 1) continue;
    // assert(lcp_s[i] + lcs_s[i] < s1[i].size() - 1);
    // ins(s1[i].substr(1)), ins(s2[i].substr(1));

    std::string str = s1[i].substr(s1[i].size() - lcs_s[i]);
    std::reverse(str.begin(), str.end());
    ins(str);
    int len = s1[i].size() - 1, pos = getpos(str);
    poss[i] = pos;
    u64 hs = gethash(hs_s1[i], 1, len - lcs_s[i]) * pw[len - lcs_s[i]] + gethash(hs_s2[i], 1, len - lcs_s[i]);
    hss[i] = hs;
    if (!id.count(hs)) id[hs] = ++id_tot;
    ids[i] = id[hs];
  }
  for (int i = 1; i <= q; ++i) {
    std::cin >> t1[i] >> t2[i];
    t1[i] = " " + t1[i], t2[i] = " " + t2[i];
    hs_t1[i].resize(t1[i].size(), 0), hs_t2[i].resize(t2[i].size(), 0);
    for (int j = 1; j < t1[i].size(); ++j) {
      hs_t1[i][j] = 13331ull * hs_t1[i][j - 1] + t1[i][j];
    }
    for (int j = 1; j < t2[i].size(); ++j)
      hs_t2[i][j] = 13331ull * hs_t2[i][j - 1] + t2[i][j];
    if (t1[i].size() != t2[i].size()) continue;
    lcp_t[i] = getlcp(t1[i], t2[i]), lcs_t[i] = getlcs(t1[i], t2[i]);
    // ins(t1[i].substr(1)), ins(t2[i].substr(1));

    std::string str = t1[i].substr(t1[i].size() - lcs_t[i]);
    std::reverse(str.begin(), str.end());
    ins(str);
    post[i] = getpos(str);

    int len = t1[i].size() - 1;
    u64 hs = gethash(hs_t1[i], 1, len - lcs_t[i]) * pw[len - lcs_t[i]] + gethash(hs_t2[i], 1, len - lcs_t[i]);
    hst[i] = hs;
  }
  build();
  for (int i = 1; i <= n; ++i) {
    diff[ids[i]].emplace_back(dfn[poss[i]], 1);
    diff[ids[i]].emplace_back(dfn[poss[i]] + sz[poss[i]], -1);
  }
  for (int i = 1; i <= id_tot; ++i) {
    std::sort(diff[i].begin(), diff[i].end());
    for (int j = 0, now = 0; j < diff[i].size(); ++j) {
      now += diff[i][j].second;
      pre[i].emplace_back(now);
    }
  }
  for (int i = 1; i <= q; ++i) {
    //   if (hss[j] == hst[i])
    //     std::cerr << i << ' ' << j << '\n';
    // }
    if (t1[i].size() != t2[i].size()) continue;
    int len = t1[i].size() - 1;
    int ans = 0;
    for (int p = 1; p <= lcp_t[i] + 1; ++p) {
      u64 hs = gethash(hs_t1[i], p, len - lcs_t[i]) * pw[len - lcs_t[i] - p + 1] + gethash(hs_t2[i], p, len - lcs_t[i]);
      if (!id.count(hs)) continue;
      int nid = id[hs];
      ans += getsum(diff[nid], pre[nid], dfn[post[i]]);
      // for (int j = 1; j <= n; ++j) {
      //   if (ids[j] == nid) {
      //     // std::cerr << "fuck " << i << ' ' << p << ' ' << j << '\n';
      //     // int now = post[i];
      //     // for (; now && now != poss[j]; now = fail[now]) {}
      //     // if (now == poss[j]) ++ans;
      //     if (dfn[poss[j]] <= dfn[post[i]] && dfn[post[i]] <= dfn[poss[j]] + sz[poss[j]] - 1)
      //       ++ans;
      //   }
      // }
    }
    res[i] = ans;
  }
  for (int i = 1; i <= q; ++i) std::cout << res[i] << '\n';
  // for (int i = 1; i <= n; ++i) {
  //   std::string str1 = s1[i].substr()
  // }
}

int32_t main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}