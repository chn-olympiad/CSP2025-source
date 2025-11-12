#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 1e5 + 10;

int a[N], b[N], c[N];


void solve() {
  vector<int> cnt[3];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int mx = max({a[i], b[i], c[i]});
    if (mx == a[i]) {
      res += a[i];
      cnt[0].push_back(i);
    } else if (mx == b[i]) {
      res += b[i];
      cnt[1].push_back(i);
    } else {
      res += c[i];
      cnt[2].push_back(i);
    }
  }
  if (cnt[1].size() < cnt[2].size()) {
    swap(cnt[1], cnt[2]);
    swap(b, c);
  }
  if (cnt[0].size() < cnt[1].size()) {
    swap(cnt[0], cnt[1]);
    swap(a, b);
  }

  sort(cnt[0].begin(), cnt[0].end(), [&](int u, int v) {
    return min(a[u] - b[u], a[u] - c[u]) < min(a[v] - b[v], a[v] - c[v]);
  });

  for (int i = 0; i < (int)cnt[0].size() - n / 2; i++) {
    int x = cnt[0][i];
    res -= min(a[x] - b[x], a[x] - c[x]);
  }

  cout << res << endl;
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) solve();

  return 0;
}