#include <bits/stdc++.h>

using namespace std;

namespace ZeroOf149 {

constexpr int N = 5e2 + 5, Mod = 998244353;

char s[N];
int n, m, c[N], p[N], ans;

int my_main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  
  scanf("%d %d %s", &n, &m, s + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", c + i);
  std::iota(p + 1, p + n + 1, 1);
  do {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (s[i] == '1' && i - 1 - cnt < c[p[i]]) ++cnt;
    if (cnt >= m) ++ans;
  } while (std::next_permutation(p + 1, p + n + 1));
  printf("%d", ans);
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }
