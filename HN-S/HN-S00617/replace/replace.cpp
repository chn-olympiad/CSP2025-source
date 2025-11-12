#include <bits/stdc++.h>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 5e6 + 15, kL = 26;

struct A {
  int id, x;
};

int id[kL][kL], cnt, n, m, tot;
int q[kMaxN], pre[kMaxN], len[kMaxN], ans[kMaxN];
// 链式前向星：
int h[kMaxN], nxt[kMaxN], to[kMaxN], st = 1;
int tr[kMaxN], val[kMaxN];
string s, t;
map<int, int> w[kMaxN];
vector<A> p[kMaxN];

void Add(int u, int v) {
  ++st, nxt[st] = h[u], to[st] = v, h[u] = st;
}

void Build() {
  int l = 1, r = 0;
  for (q[++r] = 0; l <= r; l++) {
    int x = q[l];
    for (auto _i = w[x].begin(); _i != w[x].end(); _i++) {
      int i = (*_i).first, y = (*_i).second, z = pre[x];
      q[++r] = y;
      if (x) {
        for (; z && !w[z].count(i); z = pre[z]) {
        }
        pre[y] = w[z].count(i) ? w[z][i] : 0;
      }
    }
  }
  for (int i = 2; i <= r; i++) {
    Add(pre[q[i]], q[i]);
    // cout << pre[q[i]] << " " << q[i] << "\n";
  }
}

void Update(int x, int y) {
  if (x) {
    for (int i = x; i < kMaxN; tr[i] += y, i += i & -i) {
    }
  }
}

int Query(int x){ 
  if (x >= kMaxN) {
    return 0;
  } else {
    int ans = 0;
    for (int i = x; i >= 1; ans += tr[i], i -= i & -i) {
    }
    return ans;
  }
}

void Dfs(int u) {
  Update(len[u], val[u]);
  for (int _i = 0; _i < p[u].size(); _i++) {
    A i = p[u][_i];
    ans[i.id] += Query(kMaxN - 1) - Query(i.x - 1);
  }
  for (int i = h[u]; i; i = nxt[i]) {
    int v = to[i];
    Dfs(v);
  }
  Update(len[u], -val[u]);
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      id[i][j] = cnt++;
    }
  }
  cin >> n >> m;
  int l = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s >> t;
    int pos = 0;
    for (int j = 0; j < s.size(); j++) {
      int x = id[s[j] - 'a'][t[j] - 'a'];
      !w[pos][x] && (w[pos][x] = ++tot);
      pos = w[pos][x], len[pos] = j + 1;
    }
    val[pos]++;
    l += s.size() + t.size();
  }
  Build();
  for (int i = 1; i <= m; i++) {
    cin >> s >> t;
    l += s.size() + t.size();
    int pl = -1, pr = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != t[j]) {
        (pl == -1) && (pl = j);
        pr = j;
      }
    }
    int pos = 0;
    for (int j = 0; j < s.size(); j++) {
      int x = id[s[j] - 'a'][t[j] - 'a'];
      if (!w[pos].count(x)) {
        int v = pos;
        for (; v && !w[v].count(x); v = pre[v]) {
        }
        w[pos][x] = !w[v].count(x) ? 0 : w[v][x];
        pos = !w[v].count(x) ? 0 : w[v][x];
      } else {
        pos = w[pos][x];
      }
      if (j >= pr) {
        p[pos].push_back({i, j - pl + 1});
      }
    }
  }
  // cout << l << "\n";
  // cout << val[4] << "\n";
  Dfs(0);
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }
  // cout << clock() / 1000;
  return 0;
}
// g++ replace.cpp -o replace -std=c++14 -O2 -Wall && ./replace