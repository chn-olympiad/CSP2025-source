#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using str = string;

constexpr int N = 2e5 + 5, base = 137;
int n, q, cnt, sx[N], sy[N], tx[N], ty[N], ts[N], tp[N], ss[N], sp[N], look[N];
str s[N][2], t[N][2];
vector<int> f[N], g[N];
ll ans[N];

unordered_map<u64, int> gp;

struct trie {
  int tr[5000005][26], dfn[50000005], out[50000005];
  int cnt, c;
  void clear() {
    memset(tr, 0, sizeof(int) * (cnt + 2) * 26);
    cnt = 1, c = 0;
  }
  int add(const str& s) {
    int p = 1;
    for (auto x : s) {
      x -= 'a';
      if (!tr[p][x]) tr[p][x] = ++cnt;
      p = tr[p][x];
    }
    return p;
  }
  int find(const str& s) {
    int p = 1;
    for (auto x : s) {
      x -= 'a';
      if (!tr[p][x]) return 0;
      p = tr[p][x];
    }
    return p;
  }
  void dfs(int x = 1) {
      // cerr << x << endl;
    dfn[x] = ++c;
    for (int i = 0; i < 26; i++) {
      if (tr[x][i]) dfs(tr[x][i]);
    }
    out[x] = c;
  }
} P, S;

struct node {
  int x, y, ty, id;
  friend bool operator<(const node& a, const node& b) {
    return a.x == b.x ? abs(a.ty) > abs(b.ty) : a.x < b.x;
  }
} msk[N * 6];
int tot = 0;

struct fw {
  int tr[5000005];
  void add(int x, int v) {
    while (x < 5000005) {
      // cerr << "??"<<x << endl;
      tr[x] += v;
      x += x & -x;
    }
  }
  int query(int x) {
    int ans = 0;
    while (x) {
      ans += tr[x];
      x -= x & -x;
    }
    return ans;
  }
} fw;

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  // freopen("replace.err", "w", stderr);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    if (s[i][0] == s[i][1]) continue;
    int x = 0, y = (int)s[i][0].size() - 1;
    while (s[i][0][x] == s[i][1][x]) ++x;
    while (s[i][0][y] == s[i][1][y]) --y;
    sx[i] = x, sy[i] = y;
    str a = s[i][0].substr(x, y - x + 1) + s[i][1].substr(x, y - x + 1);
    u64 z = 0;
    for (auto x : a) z = z * base + x;
    if (!gp.count(z)) gp[z] = ++cnt;
    f[gp[z]].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    cin >> t[i][0] >> t[i][1];
    int x = 0, y = (int)t[i][0].size() - 1;
    while (t[i][0][x] == t[i][1][x]) ++x;
    while (t[i][0][y] == t[i][1][y]) --y;
    tx[i] = x, ty[i] = y;
    str a = t[i][0].substr(x, y - x + 1) + t[i][1].substr(x, y - x + 1);
    u64 z = 0;
    for (auto x : a) z = z * base + x;
    if (!gp.count(z)) {}
    else {
      g[gp[z]].push_back(i);
    }
  }
  // cerr << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    if (g[i].empty()) continue;
    // cerr << f[i].size() << ' ' << g[i].size() << endl;
    P.clear(), S.clear(), tot = 0;
    for (auto j : g[i]) {
      str z = t[j][0].substr(0, tx[j]);
      reverse(z.begin(), z.end());
      tp[j] = P.add(z);
      z = t[j][0].substr(ty[j] + 1);
      ts[j] = S.add(z);
    }
    P.dfs(), S.dfs();
    for (auto j : g[i]) {
      tp[j] = P.dfn[tp[j]];
      ts[j] = S.dfn[ts[j]];
      msk[++tot] = {tp[j], ts[j], 0, j};
    }
    for (auto j : f[i]) {
      str z = s[j][0].substr(0, sx[j]);
      reverse(z.begin(), z.end());
      int x = P.find(z);
      z = s[j][0].substr(sy[j] + 1);
      int y = S.find(z);
      if (x == 0 || y == 0) continue;
      msk[++tot] = {P.dfn[x], S.dfn[y], 1, 0};
      msk[++tot] = {P.dfn[x], S.out[y] + 1, -1, 0};
      msk[++tot] = {P.out[x] + 1, S.dfn[y], -1, 0};
      msk[++tot] = {P.out[x] + 1, S.out[y] + 1, 1, 0};
    }
    // cerr << tot << endl;
    sort(msk + 1, msk + tot + 1);
    for (int j = 1; j <= tot; j++) {
      auto [x, y, ty, id] = msk[j];
      if (ty == 0) {
        ans[id] += fw.query(y);
      } else {
        fw.add(y, ty);
      }
    }
    for (int j = 1; j <= tot; j++) {
      auto [x, y, ty, id] = msk[j];
      if (ty != 0) {
        fw.add(y, -ty);
      }
    }
    // cerr << P.cnt << ' ' << S.cnt << endl;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
  return 0;
}