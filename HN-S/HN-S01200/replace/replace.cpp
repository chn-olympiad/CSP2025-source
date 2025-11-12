#include <bits/stdc++.h>

using namespace std;
bool fff;
const int MAXN = 2e5 + 5, MAXS = 5e6 + 5;

struct Node {
  int op, len, u, l, r;
  bool operator <(const Node &i) const {
    return (len == i.len ? abs(op) > abs(i.op) : len > i.len);
  }
} q[MAXS];

struct BIT {
  int n, tr[MAXS];

  inline int lowbit(int x) {
    return x & (-x);
  }

  void add(int x, int k) {
    for (; x <= n; x += lowbit(x)) {
      tr[x] += k;
    }
  }

  void Erase(int x) {
    for (; x <= n; x += lowbit(x)) {
      tr[x] = 0;
    }
  }

  int query(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) {
      ret += tr[x];
    }
    return ret;
  }
} bit;

long long ans[MAXN];
vector<int> t, a[2][MAXN], g[MAXS];
int n, m = 1, k, T, tot, L[MAXN], len[MAXN], lcp[MAXN], lcs[MAXN], ending[2][MAXN], son[MAXS][26], go[MAXS][26], fail[MAXS], dfn[MAXS], bk[MAXS];

int Insert(string &s, vector<int> &a) {
  int u = 1;
  for (auto ch : s) {
    int now = ch - 'a';
    if (!son[u][now]) son[u][now] = ++m;
    u = son[u][now], a.push_back(u);
  }
  return u;
}

void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    go[1][i] = 1;
    if (son[1][i]) {
      go[1][i] = son[1][i], fail[son[1][i]] = 1, q.push(son[1][i]);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    g[fail[u]].push_back(u), q.pop();
    //cout << u << ' ' << fail[u] << '\n';
    for (int i = 0; i < 26; i++) {
      if (son[u][i]) {
        go[u][i] = son[u][i], fail[son[u][i]] = go[fail[u]][i], q.push(son[u][i]);
      } else {
        go[u][i] = go[fail[u]][i];
      }
    }
  }
}

void dfs(int x) {
  dfn[x] = ++tot;
  for (auto y : g[x]) {
    dfs(y);
  }
  bk[x] = tot;
}

void solve(int l, int r) {
  if (l == r) return ;
  int mid = (l + r) >> 1;
  solve(l, mid), solve(mid + 1, r);
  for (int i = mid + 1, j = l; i <= r; i++) {
    for (; j <= mid && q[j].u <= q[i].u; j++) {
      if (q[j].op) bit.add(q[j].l, q[j].op), bit.add(q[j].r + 1, -q[j].op);
    }
    if (!q[i].op) ans[q[i].r] += bit.query(q[i].l);
  }
  for (int i = l; i <= mid; i++) {
    bit.Erase(q[i].l), bit.Erase(q[i].r + 1);
  }
  sort(q + l, q + r + 1, [](Node &i, Node &j) {
    return i.u < j.u;
  });
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    string s1, s2;
    cin >> s1 >> s2, L[i] = s1.size();
    ending[0][i] = Insert(s1, t);
    ending[1][i] = Insert(s2, t);
  }
  for (int i = 1; i <= T; i++) {
    string s1, s2; cin >> s1 >> s2, len[i] = s1.size();
    if (len[i] != s2.size()) {
      len[i] = 0; continue;
    }
    Insert(s1, a[0][i]), Insert(s2, a[1][i]);
    for (; lcp[i] < len[i] && s1[lcp[i]] == s2[lcp[i]]; lcp[i]++);
    for (lcs[i] = len[i]; lcs[i] >= 0 && s1[lcs[i]] == s2[lcs[i]]; lcs[i]--);
    //lcp[i]--;
  }
  build(), dfs(1), bit.n = m;
  fill(bit.tr, bit.tr + m + 1, 0);
  for (int i = 1; i <= n; i++) {
    //cout << dfn[ending[1][i]] << ' ' << bk[ending[1][i]] << ' ' << dfn[ending[0][i]] << ' ' << bk[ending[0][i]] << '\n';
    q[++k] = {1, L[i], dfn[ending[1][i]], dfn[ending[0][i]], bk[ending[0][i]]};
    q[++k] = {-1, L[i], bk[ending[1][i]] + 1, dfn[ending[0][i]], bk[ending[0][i]]};
  }
  for (int i = 1; i <= T; i++) {
    if (!len[i]) continue;
    for (int j = lcs[i]; j < len[i]; j++) {
      q[++k] = {0, max(1, j - lcp[i] + 1), dfn[a[1][i][j]], dfn[a[0][i][j]], i};
      //cout << "f: " << ' ' << i << ' ' << j << ' ' << lcp[i] << ' ' << j - lcp[i] << ' ' << dfn[a[1][i][j]] << ' ' << dfn[a[0][i][j]] << '\n';
    }
  }
  sort(q + 1, q + k + 1);
  solve(1, k);
  for (int i = 1; i <= T; i++) {
    cout << ans[i] << '\n';
  }
  //bool eee;
  //cout << (&eee - &fff) /1024/1024;
  return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 2
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
