#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

int n, a[N][3];
std::vector<int> p[3];

inline void solve() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) {
    p[i].clear();
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    int mx = 0;
    for (int j = 1; j <= 2; j++) {
      if (a[i][j] > a[i][mx]) {
        mx = j;
      }
    }
    p[mx].push_back(i);
    ans += a[i][mx];
  }

  for (int i = 0; i < 3; i++) {
    if ((int)p[i].size() <= n / 2) {
      continue;
    }
    std::vector<int> val;
    for (int x : p[i]) {
      int delta = (int)-1e9;
      for (int j = 0; j < 3; j++) {
        if (j != i) {
          delta = std::max(a[x][j] - a[x][i], delta);
        }
      }
      val.push_back(delta);
    }
    std::sort(val.begin(), val.end());
    for (int j = n / 2; j < (int)val.size(); j++) {
      ans += val[j];
    }
  }
  printf("%d\n", ans);
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}