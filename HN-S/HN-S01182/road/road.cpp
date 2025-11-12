#include <bits/stdc++.h>

using namespace std;
using LL = long long;

ifstream fin("road.in");
ofstream fout("road.out");

const int kMaxN = 10001, kMaxM = 1e6 + 1, kMaxK = 11;

array<int, 3> e[kMaxM];
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
    fin >> a[i][0];
    for (int j = 1; j <= n; j++) {
      fin >> a[i][j];
      ++m, e[m][0] = a[i][j], e[m][1] = j, e[m][2] = n + i + 1;
    }
  }
  stable_sort(e + 1, e + 1 + m);
  for (int s = 0; s < 1 << k; s++) {
    sum = 0;
    fill(f + 1, f + 1 + n + k, 0);
    for (int i = 0; i < k; i++) {
      if (s >> i & 1) {
        sum += a[i][0];
      }
    }
    for (int i = 1; i <= m; i++) {
      if (e[i][2] <= n || (s >> (e[i][2] - 1 - n) & 1)) {
        int x = R(e[i][1]), y = R(e[i][2]);
        if (x != y) {
          sum += e[i][0];
          f[x] = y;
        }
      }
    }
    ans = min(ans, sum);
  }
  fout << ans;
  return 0;
}