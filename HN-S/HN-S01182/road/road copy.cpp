#include <bits/stdc++.h>

using namespace std;
using LL = long long;

ifstream fin("road.in");
ofstream fout("road.out");

const int kMaxN = 10001, kMaxM = 1e6 + 1, kMaxK = 11;

array<int, 3> e[kMaxM], e2[kMaxM];
int a[kMaxK][kMaxN], f[kMaxN + kMaxK], n, m, m2, k;
LL ans = 1e18, sum;

int R(int x) { return f[x] ? f[x] = R(f[x]) : x; }

int main() {
  fin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    fin >> e[i][1] >> e[i][2] >> e[i][0];
  }
  stable_sort(e + 1, e + 1 + m);
  for (int i = 1; i <= m; i++) {
    int x = R(e[i][1]), y = R(e[i][2]);
    if (x != y) {
      e[++m2] = e[i];
      f[x] = y;
    }
  }
  m = m2;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= n; j++) {
      fin >> a[i][j];
    }
  }
  for (int s = 0; s < 1 << k; s++) {
    m2 = m, sum = 0;
    copy(e + 1, e + 1 + m, e2 + 1);
    fill(f + 1, f + 1 + n + k, 0);
    for (int i = 0; i < k; i++) {
      if (s >> i & 1) {
        sum += a[i][0];
        for (int j = 1; j <= n; j++) {
          ++m2, e2[m2][0] = a[i][j], e2[m2][1] = j, e2[m2][2] = n + i + 1;
        }
      }
    }
    stable_sort(e2 + 1, e2 + 1 + m2);
    for (int i = 1; i <= m2; i++) {
      int x = R(e2[i][1]), y = R(e2[i][2]);
      if (x != y) {
        sum += e2[i][0];
        f[x] = y;
      }
    }
    ans = min(ans, sum);
  }
  fout << ans;
  return 0;
}