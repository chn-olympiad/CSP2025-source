#include <bits/stdc++.h>

using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");

const int kMaxN = 1e5 + 1;

int a[kMaxN][3], b[kMaxN][3], c[3], n, t, ans, o;

int main() {
  for (fin >> t; t--; ) {
    fin >> n;
    c[0] = c[1] = c[2] = ans = 0;
    for (int i = 1; i <= n; i++) {
      fin >> a[i][0] >> a[i][1] >> a[i][2];
      b[i][0] = 0, b[i][1] = 1, b[i][2] = 2;
      sort(b[i], b[i] + 3, [i](int j1, int j2) { return a[i][j1] > a[i][j2]; } );
      c[b[i][0]]++, ans += a[i][b[i][0]];
    }
    for (o = 0; o <= 2 && c[o] <= n / 2; o++) {
    }
    if (o <= 2) {
      vector<int> d;
      for (int i = 1; i <= n; i++) {
        if (b[i][0] == o) {
          d.emplace_back(a[i][b[i][0]] - a[i][b[i][1]]);
        }
      }
      sort(d.begin(), d.end());
      for (int i = 0; i < c[o] - n / 2; i++) {
        ans -= d[i];
      }
    }
    fout << ans << '\n';
  }
  return 0;
}