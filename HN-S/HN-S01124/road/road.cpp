#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFile = "road";
ifstream cin(kFile + ".in");
ofstream cout(kFile + ".out");
#endif

const int kN = 1e4 + 1, kM = 1e6 + 1, kK = 10;

struct E {
  int x, y, w;

  bool operator<(const E &o) const { return w < o.w; }
} e[kM], ek[kK][kN], ep[kK + 1][kN * 2 + kK];
int n, m, k, c[kK], f[kN + kK], s[kN + kK];
ll ans;

int F(int x) { return f[x] ? (f[x] = F(f[x])) : x; }
bool M(int x, int y) {
  x = F(x), y = F(y);
  if (x == y) {
    return 0;
  }
  if (s[x] > s[y]) {
    swap(x, y);
  }
  s[y] += s[x], f[y] = x;
  return 1;
}
void D(int i, ll w, int n) {
  if (i == k) {
    // cerr << _S << endl;
    for (int j = 1; j < n; ++j) {
      // cerr << ep[k][j].x << ' ' << ep[k][j].y << endl;
      w += ep[k][j].w;
    }
    // cerr << _S << ' ' << w << endl;
    ans = min(ans, w);
    return;
  }
  copy_n(ep[i] + 1, n - 1, ep[i + 1] + 1);
  D(i + 1, w, n);
  merge(ep[i] + 1, ep[i] + n, ek[i] + 1, ek[i] + ::n + 1, ep[i + 1] + 1);
  fill_n(f + 1, ::n + k, 0), fill_n(s + 1, ::n + k, 1);
  for (int j = 1, c = 0; j < n + ::n && c < n + 1; ++j) {
    if (M(ep[i + 1][j].x, ep[i + 1][j].y)) {
      ep[i + 1][++c] = ep[i + 1][j];
    }
  }
  D(i + 1, w + c[i], n + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  sort(e + 1, e + m + 1);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      cin >> ek[i][j].w;
      ek[i][j].x = n + i + 1, ek[i][j].y = j;
    }
    sort(ek[i] + 1, ek[i] + n + 1);
  }
  fill_n(s + 1, n, 1);
  for (int i = 1, j = 0; i <= m && j < n - 1; ++i) {
    if (M(e[i].x, e[i].y)) {
      ans += e[i].w;
      ep[0][++j] = e[i];
    }
  }
  D(0, 0, n);
  cout << ans;
  return 0;
}