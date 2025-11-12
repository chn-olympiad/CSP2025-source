#include <bits/stdc++.h>

using namespace std;

namespace ZeroOf149 {

constexpr int N = 1e5 + 5, A = 3 + 1;

int T, n, a[N][A], mxpos[N], cnt[A], dif[N], tmp[N];

int my_main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int ans = 0;
    for (int c = 0; c < 3; ++c) cnt[c] = 0;
    for (int i = 1; i <= n; ++i) {
      mxpos[i] = 0;
      for (int c = 0; c < 3; ++c) scanf("%d", a[i] + c);
      for (int c = 0; c < 3; ++c)
        if (a[i][c] > a[i][mxpos[i]]) mxpos[i] = c;
      ans += a[i][mxpos[i]];
      ++cnt[mxpos[i]];
      std::sort(a[i], a[i] + 3);
      dif[i] = a[i][2] - a[i][1];
    }
    std::iota(tmp + 1, tmp + n + 1, 1);
    std::sort(tmp + 1, tmp + n + 1, [&](int i, int j){ return dif[i] < dif[j]; });
    int mxc = 0;
    for (int c = 0; c < 3; ++c)
      if (cnt[c] > cnt[mxc]) mxc = c;
    for (int i = 1; i <= n && cnt[mxc] > n / 2; ++i)
      if (mxpos[tmp[i]] == mxc) {
        ans -= dif[tmp[i]];
        --cnt[mxc];
      }
    printf("%d\n", ans);
  }
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }
