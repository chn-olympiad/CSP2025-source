#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...) void(0)
#define endl "\n"
#endif
using LL = long long;
constexpr int M = 5e6 + 10, N = 2e5 + 10;
int n, q, tr[M][27], tot, tid[M], cid, fail[M], dep[M], ct[M];
LL fans[N];
vector<string> ss[N * 2];
vector<pair<string, int>> ts[N * 2];
void build() {
  fail[0] = 0, dep[0] = 0;
  queue<int> q;
  for (int i = 0; i < 27; i++) if (tr[0][i]) q.push(tr[0][i]), fail[tr[0][i]] = 0, dep[tr[0][i]] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < 27; i++) {
      if (tr[u][i]) q.push(tr[u][i]), fail[tr[u][i]] = tr[fail[u]][i], dep[tr[u][i]] = dep[u] + 1;
      else tr[u][i] = tr[fail[u]][i];
    }
  }
  static int buc[M], per[M];
  for (int i = 0; i <= tot; i++) buc[i] = 0;
  for (int i = 0; i <= tot; i++) buc[dep[i]] += 1;
  for (int i = 1; i <= tot; i++) buc[i] += buc[i - 1];
  for (int i = tot; i >= 0; i--) per[--buc[dep[i]]] = i;
  for (int i = 1; i <= tot; i++) ct[per[i]] += ct[fail[per[i]]];
}
int main() {
#ifndef LOCAL
#ifndef NF
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  cin >> n >> q;
  for (int o = 0; o < 2; o++) {
    for (int i = 1; i <= (o ? q : n); i++) {
      string s1, s2;
      cin >> s1 >> s2;
      if (s1 == s2) continue;
      if (s1.size() != s2.size()) continue;
      int p1 = 0, p2 = (int)s1.size();
      while (s1[p1] == s2[p1]) ++p1;
      while (s1[p2 - 1] == s2[p2 - 1]) --p2;
      int u = 0;
      bool flag = true;
      for (int j = p1; j < p2; j++) {
        int r = s1[j] - 'a';
        if (!tr[u][r]) {
          if (o == 0) tr[u][r] = ++tot;
          else { flag = false; break; }
        }
        u = tr[u][r];
        r = s2[j] - 'a';
        if (!tr[u][r]) {
          if (o == 0) tr[u][r] = ++tot;
          else { flag = false; break; }
        }
        u = tr[u][r];
      }
      if (flag) {
        if (!tid[u]) tid[u] = ++cid;
        auto others = s1.substr(0, p1) + '{' + s1.substr(p2);
        if (o) ts[tid[u]].emplace_back(others, i);
        else ss[tid[u]].push_back(others);
      }
    }
  }
  for (int c = 1; c <= cid; c++) if (!ss[c].empty() && !ts[c].empty()) {
    debug("clr\n");
    tot = 0, memset(tr[0], 0, sizeof tr[0]), ct[0] = 0;
    for (auto s : ss[c]) {
      debug("s: %s\n", s.c_str());
      int u = 0;
      for (char ch : s) {
        int r = ch - 'a';
        if (!tr[u][r]) tr[u][r] = ++tot, memset(tr[tot], 0, sizeof tr[0]), ct[tot] = 0;
        u = tr[u][r];
      }
      ct[u] += 1;
    }
    build();
    for (auto [t, id] : ts[c]) {
      debug("t: %s %d\n", t.c_str(), id);
      int u = 0;
      LL &ans = fans[id];
      for (char ch : t) {
        int r = ch - 'a';
        u = tr[u][r];
        ans += ct[u];
      }
    }
  }
  for (int i = 1; i <= q; i++) cout << fans[i] << endl;
  return 0;
}

