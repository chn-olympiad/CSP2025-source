#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxm = 1000010;
const int maxn = 11015;
int n, m, K;
int cnt;
int Sum;
int N, M;
int f[maxn];
struct E {
  int x, y;
  ll w;
  bool operator < (const E & _) const {
    return w < _.w;
  }
} e[maxm], ee[maxn * 20];
ll c[12];
ll a[12][maxn];
int find (int x) {
  if (f[x] == x) return x;
  return f[x] = find (f[x]);
}

ll solve () {

  ll res = 0;
  sort (e + 1, e + M + 1);
  for (int i = 1; i <= N; i++) f[i] = i;
  for (int i = 1; i <= M; i++) {
    auto [u, v, w] = e[i];
    if (find (u) != find (v)) {
      f[find (u)] = find (v);
      res += w;
    }
  }
  return res;
}
bool checkA () {
  for (int i = 1; i <= K; i++) {
    if (c[i]) return false;
    bool flag = false;
    for (int j= 1; j <= n; j++) {
      flag |= !a[i][j];
    }
    if (!flag) return false;
  }
  return true;
}



int main () {
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (false);
  cin >> n >> m >> K;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  for (int i = 1; i <= K; i++) {
    cin >> c[i];
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }


  if (!K) {
    N = n; M = m;
    cout << solve() << '\n';
    return 0;
  }
  if (checkA ()) {
    M = m;
    for (int i = 1; i <= K; i++) {
      for (int j = 1; j <= n; j++) {
        e[++M] = E {n + i, j, a[i][j]};
      }
    }
    N = n + K;
    cout << solve () << '\n';
    return 0;
  }

  sort (e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    auto [u, v, w] = e[i];
    if (find (u) != find (v)) {
      f[find (u)] = find (v);
      ee[++M] = e[i];
    }
  }
  N = n;
  for (int i = 1; i < n; i++) e[i] = ee[i];
  // cout << solvee () << endl;
  ll ans = 1e18;
  // cerr << clock () / 1000 << endl;
  for (int _ = 0; _ < (1 << K); _++) {
    ll res = 0;
    // M = m;
    for (int i = 1; i < n; i++) ee[i] = e[i];
    M = n - 1;
    N = n + K;
    for (int i = 1; i <= K; i++) {
      if ((_ >> i - 1) & 1) {
        res += c[i];
        for (int j = 1; j <= n; j++)
          ee[++M] = E {n + i, j, a[i][j]};
      }
    }
    if (res > ans) continue;
    Sum += M;
    stable_sort (ee + 1, ee + M + 1);
    for (int i = 1; i <= N; i++) f[i] = i;
    for (int i = 1; i <= M && res < ans; i++) {
      auto [u, v, w] = ee[i];
      if (find (u) != find (v)) {
        f[find (u)] = find (v);
        res += w;
      }
    }
    ans = min (ans, res);
  }
  cout << ans << '\n';
  
  // cerr << clock () / 1000 << endl;
  // cerr << Sum << endl;
  return 0;
}