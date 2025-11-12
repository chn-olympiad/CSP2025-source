#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using pii = pair<int, int>;

void read() {}
template<typename T, typename... U> void read(T &x, U&... arg) {
  x = 0; int f = 1; char ch = getchar();
  while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f; read(arg...);
}

void write() {}
template<typename T> void write(T x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}

template<typename T, typename U> void write(T x, U y) {
  write(x); putchar(y);
}


#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define adj(g, u, v) for (int _eid = g.head[u], v; v = g.ver[_eid], _eid; _eid = g.Next[_eid])

const int N = 1e5 + 5;

int T, n, a[N][4];
bool b[N];

void solve() {
  read(n);
  priority_queue<pii> que[4][4];
  vector<int> cnt(4, 0); int ans = 0;
  rep(i, 1, n) rep(j, 1, 3) read(a[i][j]);


  rep(i, 1, n) {
    int mp = 1;
    rep(j, 2, 3) if (a[i][j] > a[i][mp]) mp = j;

    if (cnt[mp] < n / 2) {
      cnt[mp]++; ans += a[i][mp];
      rep(j, 1, 3) if (j != mp) que[mp][j].push({a[i][j] - a[i][mp], i});
    } else {
      int sp = (mp == 1 ? 2 : 1);
      rep(j, 1, 3) if (j != mp && j != sp) if (a[i][j] > a[i][sp]) sp = j;
      int Max = -1e9, s = 0;
      rep(j, 1, 3) if (j != mp) while (b[que[mp][j].top().second]) que[mp][j].pop();
      rep(j, 1, 3) if (j != mp) if (a[i][mp] + que[mp][j].top().first > Max)
        Max = a[i][mp] + que[mp][j].top().first, s = j;

      if (Max > a[i][sp]) {
        ans += Max; cnt[s]++; b[que[mp][s].top().second] = 1, que[mp][s].pop();
        rep(j, 1, 3) if (j != mp) que[mp][j].push({a[i][j] - a[i][mp], i});
      } else ans += a[i][sp], cnt[sp]++;
    }

  }

  write(ans, '\n');
  memset(b, 0, sizeof(b));
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  read(T);
  while (T--) solve();
  return 0;
}
