#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##e = (r); i <= i##e; i++)
#define repp(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define per(i, r, l) for (int i = (r), i##e = (l); i >= i##e; i--)

using namespace std;
using ll = long long;

template <class T>
void chkMax(T &a, T b) {
  a = max(a, b);
}
template <class T>
void chkMin(T &a, T b) {
  a = min(a, b);
}
template <class... Args>
void println(Args... args) {
  ((cerr << args << " "), ...);
  cerr << "\n";
}

const int N = 1e5 + 4, INF = 0x3f3f3f3f;
int n;
int v[N][4];

void solve1() {
  vector<vector<int>> f(n + 1, vector<int>(n + 1, -INF));
  f[0][0] = 0;
  rep(i, 1, n) {
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -INF));
    rep(a, 0, n) rep(b, 0, n) {
      if (i - a - b <= n / 2)chkMax(g[a][b], f[a][b] + v[i][3]);
      if (a && a <= n / 2) chkMax(g[a][b], f[a - 1][b] + v[i][1]);
      if (b && b <= n / 2) chkMax(g[a][b], f[a][b - 1] + v[i][2]);
    }
    swap(f, g);
  }
  int ans = -INF;
  rep(a, 0, n) rep(b, 0, n)
    if(a <= n / 2 && b <= n / 2 && (n - a - b) <= n / 2)
    chkMax(ans, f[a][b]);
  cout << ans << "\n";
}

void solve2() {
  vector<int> a(n + 1);
  rep(i, 1, n)
    a[i] = v[i][1];
  sort(a.begin() + 1, a.end(), greater<>());
  int sum = 0;
  rep(i, 1, n / 2) sum += a[i];
  cout << sum << "\n";
}

void solve() {
  cin >> n;
  int hve2 = 0, hve3 = 0;
  rep(i, 1, n) {
    rep(j, 1, 3) cin >> v[i][j];
    chkMax(hve2, v[i][2]);
    chkMax(hve3, v[i][3]);
  }
  if(n <= 200)
    solve1();
  else if(!hve2 && !hve3)
    solve2();
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}