#include <iostream>
#include <vector>
#include <map>

using namespace std;

void file () {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
}

const int kN = int(2e5) + 5;
const int kL = int(2.5e6) + 5;

int n, q;

struct string_pair {
  string s[2];
  int len;

  void read () {
    cin >> s[0] >> s[1];
    if (s[0].size() != s[1].size()) {
      len = 0;
      return;
    }
    int mi = s[0].size(), mx = -1;
    for (int i = 0; i < s[0].size(); ++i) {
      if (s[0][i] != s[1][i]) {
        mi = min(mi, i);
        mx = max(mx, i);
      }
    }
    if (mx == -1) len = 0; 
    else len = mx - mi + 1;
  }

  vector<int> get_hash () {
    vector<int> res(s[0].size());
    for (int i = 0; i < s[0].size(); ++i) {
      res[i] = (s[0][i] - 'a') * 26 + (s[1][i] - 'a');
    }
    return res;
  }
} s[kN], t[kN];

int ans[kN];

vector<int> vs[kL], vt[kL];

struct ACAM {
  int tot;
  map<int, int> tr[kL];
  int fail[kL], cnt[kL];
  int q[kL];

  void init () {
    tot = 0;
    tr[0].clear();
    fail[0] = cnt[0] = 0; 
  }

  int new_node () {
    ++tot;
    tr[tot].clear();
    fail[tot] = cnt[tot] = 0; 
    return tot;
  }

  void insert (vector<int> a) {
    int k = 0; 
    for (auto v : a) {
      if (!tr[k].count(v)) {
        tr[k][v] = new_node();
      }
      k = tr[k][v];
    }
    ++cnt[k];
  }

  void build () {
    for (int h = 0, t = 0; h <= t; ++h) {
      int u = q[h];
      for (auto i : tr[u]) {
        int x = i.first, v = i.second;
        if (u) {
          int w = fail[u];
          while (true) {
            if (tr[w].count(x)) {
              fail[v] = tr[w][x];
              break;
            }
            if (!w) break;
            w = fail[w];
          }
        }
        q[++t] = v;
      }
    }
    for (int i = 1; i <= tot; ++i) {
      cnt[q[i]] += cnt[fail[q[i]]];
    }
  }

  int query (vector<int> a) {
    int k = 0; 
    int res = 0; 
    for (auto v : a) {
      while (k && !tr[k].count(v)) {
        k = fail[k];
      }
      if (tr[k].count(v)) {
        k = tr[k][v];
      }
      res += cnt[k];
    }
    return res;
  }
} am;

void solve (int len) {
  if (vs[len].empty() || vt[len].empty()) return; 
  am.init();
  for (auto i : vs[len]) {
    vector<int> a = s[i].get_hash();
    am.insert(a);
  }
  am.build();
  for (auto i : vt[len]) {
    vector<int> a = t[i].get_hash();
    ans[i] = am.query(a);
  }
}

void fakemain () {
  cin >> n >> q;
  int mxl = 0;
  for (int i = 1; i <= n; ++i) {
    s[i].read();
    vs[s[i].len].push_back(i);
    mxl = max(mxl, s[i].len);
  }
  for (int i = 1; i <= q; ++i) {
    t[i].read();
    vt[t[i].len].push_back(i);
    mxl = max(mxl, t[i].len);
  }
  for (int i = 1; i <= mxl; ++i) {
    solve(i);
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << '\n';
  }
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  fakemain();
  return 0;
}