#include <bits/stdc++.h>

using namespace std;

namespace ZeroOf149 {

using ll = long long;
using pii = std::pair<int, int>;
using hash_t = std::pair<ll, ll>;
using phh = std::pair<hash_t, hash_t>;
using Str = std::string;

constexpr int N = 2e5 + 5, Ts = 2e5 + 5, L = 5e6 + 5, A = 27,
          B[2] = {131, 149}, Mod[2] = {1610612741, 998244353};

int n, T, ans[Ts];
char s1[L], s2[L];
Str rmn[N], rmt[Ts];
std::map<phh, std::vector<int> > mp, qr;

hash_t calc_hash(char* s, int len) {
  hash_t hsh = {};
  if (len <= 0) return hsh;
  for (int h = 0; h < 2; ++h) {
    auto& hh = (h ? hsh.first : hsh.second);
    for (int i = 1; i <= len; ++i) hh = (hh * B[h] + s[i]) % Mod[h];
  }
  return hsh;
}

pii find_lr(char* s, char * t, int len) {
  int l = 1;
  while (l <= len && s[l] == t[l]) ++l;
  --l;
  int r = len;
  while (r >= 1 && s[r] == t[r]) --r;
  ++r;
  return pii{l, r};
}

int tcnt = 1;

struct TR {
  int ch[A], cnt, nxt;
} tr[L];

void insert(const Str& str) {
  // fprintf(stderr, "Insert %s\n", str.c_str());
  int id = 1;
  for (auto&& chr : str) {
    int& nxt = tr[id].ch[chr - 'a'];
    if (!nxt) {
      nxt = ++tcnt;
      tr[nxt].cnt = tr[nxt].nxt = 0;
      for (auto&& c : tr[nxt].ch) c = 0;
    }
    id = nxt;
  }
  ++tr[id].cnt;
}

void init() {
  std::queue<int> q;
  for (auto&& c : tr[1].ch)
    if (c) {
      tr[c].nxt = 1;
      q.push(c);
    } else
      c = 1;
  while (!q.empty()) {
    int id = q.front();
    q.pop();
    auto&& fnxt = tr[id].nxt;
    if (fnxt != 1) tr[id].cnt += tr[fnxt].cnt;
    for (int c = 0; c < 27; ++c) {
      auto&& ch = tr[id].ch[c];
      if (!ch) {
        ch = tr[fnxt].ch[c];
        continue;
      }
      tr[ch].nxt = tr[fnxt].ch[c];
      q.push(ch);
    }
  }
}

int query(const Str& str) {
  // fprintf(stderr, "Query %s\n", str.c_str());
  int ans = tr[1].cnt, id = 1;
  for (auto&& chr : str) {
    id = tr[id].ch[chr - 'a'];
    ans += tr[id].cnt;
  }
  return ans;
}

int my_main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%s %s", s1 + 1, s2 + 1);
    int len = std::strlen(s1 + 1);
    auto lr = find_lr(s1, s2, len);
    int l = lr.first, r = lr.second;
    auto hsh_l = calc_hash(s1 + l, r - l - 1),
         hsh_r = calc_hash(s2 + l, r - l - 1);
    mp[phh{hsh_l, hsh_r}].push_back(i);
    if (l >= 1) rmn[i] += std::string(s1 + 1, s1 + l + 1);
    rmn[i] += 'a' + 26;
    if (r <= len) rmn[i] += std::string(s1 + r, s1 + len + 1);
    // printf("%d[%d %d]\n", i, l, r);
  }
  for (int t = 1; t <= T; ++t) {
    scanf("%s %s", s1 + 1, s2 + 1);
    int s1len = std::strlen(s1 + 1), s2len = std::strlen(s2 + 1);
    if (s1len != s2len) continue;
    pii slr = find_lr(s1, s2, s1len);
    int l = slr.first, r = slr.second;
    auto hsh_l = calc_hash(s1 + l, r - l - 1),
         hsh_r = calc_hash(s2 + l, r - l - 1);
    qr[phh{hsh_l, hsh_r}].push_back(t);
    if (l >= 1) rmt[t] += std::string(s1 + 1, s1 + l + 1);
    rmt[t] += 'a' + 26;
    if (r <= s1len) rmt[t] += std::string(s1 + r, s1 + s1len + 1);
  }
  for (auto&& pr : qr) {
    auto&& hsh = pr.first;
    auto&& qs = pr.second;
    if (!mp.count(hsh)) continue;
    for (int id = 1; id <= tcnt; ++id) {
      tr[id].cnt = tr[id].nxt = 0;
      for (auto&& c : tr[id].ch) c = 0;
    }
    tcnt = 1;
    for (auto&& id : mp[hsh]) insert(rmn[id]);
    init();
    for (auto&& t : qs) ans[t] = query(rmt[t]);
  }
  for (int t = 1; t <= T; ++t) printf("%d\n", ans[t]);
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }
