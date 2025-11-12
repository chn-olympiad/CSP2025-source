#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 10;

int n, m, k, u[M], v[M], w[M], sum1, sum2, a[M], fin[M];

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    sum1 += w[i];
  }
  memset(fin, 127, sizeof(fin));
  for (int i = 1; i <= k; i++) {
    int tmp;
    cin >> tmp;
    sum2 += tmp;
    for (int i = 1; i <= n; i++) cin >> a[i], fin[i] = min(fin[i], a[i]);
  }
  for (int i = 1; i <= n; i++) sum2 += fin[i];
  cout << min(sum1, sum2);
  return 0;
}
