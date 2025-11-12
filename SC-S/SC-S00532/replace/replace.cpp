#include <bits/stdc++.h>
using namespace std;

const int N = 7e5 + 5, M = 676;
using ll = long long;
struct AC_AM {
  int to[30][30], cnt = -1;
  inline int trans(char a, char b) {
    if (to[a - 'a'][b - 'a'] == -1) to[a - 'a'][b - 'a'] = ++cnt;
    return to[a - 'a'][b - 'a'];
  }
  ll f[N];
  int tot = 0, fail[N];
  int tr[N][M];
  void insert(string a, string b) {
    //cerr << a << ' ' << b << endl;
    int len = a.size(), u = 0;
    for (int i = 0; i < len; i++) {
      int s = trans(a[i], b[i]);
      if (!tr[u][s]) tr[u][s] = ++tot;
      u = tr[u][s]; 
      //cerr << a << ' ' << b << ' ' << i << ' ' << u << endl;
    }
    f[u]++;
  }
  void bfs() {
    queue<int> q;
    //cerr << "z z" << ' ' << trans('z', 'z') << endl;
    for (int i = 0; i <= cnt; i++) 
      if (tr[0][i]) q.push(tr[0][i]);
    //cerr << q.size() << endl;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = 0; i <= cnt; i++) {
        if (tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
        else tr[u][i] = tr[fail[u]][i];
      }
    }
    //for (int i = 1; i <= tot; i++) cerr << fail[i] << " \n"[i == tot];
  }
  int vis[N];
  void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1, dfs(fail[u]), f[u] += f[fail[u]];
  }
  void init() {
    vis[0] = 1;
    for (int i = 1; i <= tot; i++)
      dfs(i);
  }

  int calc(string a, string b, int l, int r) {
    ll ret = 0;
    int u = 0;
    for (int i = l; i <= r; i++) {
      int s = trans(a[i], b[i]);
      if (!tr[u][s]) u = fail[u];
      ret += f[u = tr[u][s]];
    }
    //cerr << a << ' ' << b << ' ' << ret << endl;
    return ret;
  }
}ac;

signed main() {
  freopen("replace.in", "r", stdin),
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q; cin >> n >> q; 
  memset(ac.to, -1, sizeof ac.to);
  for (int i = 1; i <= n; i++) {
    string a, b; cin >> a >> b;
    ac.insert(a, b);
  }
  ac.bfs(), ac.init();
  //string t = "01234567";
  //cerr << t.substr(0, 7) << ' ' << t.substr(2,5) << endl;
  while (q--) {
    string a, b; cin >> a >> b;
    int len = a.size();
    int st = 0, ed = a.size() - 1;
    for (int i = 0; i < len; i++) if (a[i] != b[i]) {
      st = i; break;
    }
    for (int i = len - 1; ~i; i--) if (a[i] != b[i]) {
      ed = i; break;
    }
    //cerr << a << ' ' << b << ' ' << st << ' ' << ed << endl;
    ll ans = ac.calc(a, b, 0, len - 1);
    ll del1 = ac.calc(a, b, 0, ed - 1);
    ll del2 = ac.calc(a, b, st + 1, len - 1); 
    ll add = ac.calc(a, b, st + 1, ed - 1);
    cout << ans - del1 - del2 + add << '\n';
  }
  return 0;
}