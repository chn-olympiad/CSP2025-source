// g++ -std=c++14 -O2 -fsanitize=address,undefined -o replace replace.cpp && ./replace
#include <bits/stdc++.h>

// #define int int64_t

using u64 = uint64_t;

const int kMaxN = 2e5 + 5, kMaxL = 5e6 + 5;

int n, q;
int lcp_s[kMaxN], lcs_s[kMaxN], lcp_t[kMaxN], lcs_t[kMaxN];
u64 pw[kMaxL];
std::string s1[kMaxN], s2[kMaxN], t1[kMaxN], t2[kMaxN];
std::vector<u64> hs_s1[kMaxN], hs_s2[kMaxN], hs_t1[kMaxN], hs_t2[kMaxN];

int trie_tot, trie[kMaxL][26], fail[kMaxL];

u64 gethash(std::vector<u64> &hs, int l, int r) {
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
  }
  for (int i = 1; i <= q; ++i) {
    std::cin >> t1[i] >> t2[i];
    t1[i] = " " + t1[i], t2[i] = " " + t2[i];
    hs_t1[i].resize(t1[i].size(), 0), hs_t2[i].resize(t2[i].size(), 0);
    for (int j = 1; j < t1[i].size(); ++j) {
      hs_t1[i][j] = 13331ull * hs_t1[i][j - 1] + t1[i][j];
      hs_t2[i][j] = 13331ull * hs_t2[i][j - 1] + t2[i][j];
    }
    if (t1[i].size() != t2[i].size()) continue;
    lcp_t[i] = getlcp(t1[i], t2[i]), lcs_t[i] = getlcs(t1[i], t2[i]);
  }
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