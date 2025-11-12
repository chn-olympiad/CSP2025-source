#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");

const int kN = 1e5 + 1;

int T, n, ans, a[3];
struct AC {
  int a[3];
};
vector<int> f;
vector<AC> t[3];

int Calc(int x) {
  f.clear();
  int res = 0;
  for (int i = 0; i < (int)t[x].size(); i++) {
    AC s = t[x][i];
    int mx = 0;
    for (int o : {1, 2})
      mx = max(mx, s.a[(x + o) % 3]);
    f.push_back(s.a[x] - mx);
  }
  sort(f.begin(), f.end());
  for (int i = 0; i < (int)f.size() - n / 2; i++)
    res += f[i];
  return res;
}

int main() {
  fin.tie(0)->sync_with_stdio(0);
  for (fin >> T; T--;) {
    fin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j : {0, 1, 2})
        fin >> a[j];
      if (a[0] >= a[1] && a[0] >= a[2])
        t[0].push_back({a[0], a[1], a[2]}), ans += a[0];
      else if (a[1] >= a[0] && a[1] >= a[2])
        t[1].push_back({a[0], a[1], a[2]}), ans += a[1];
      else
        t[2].push_back({a[0], a[1], a[2]}), ans += a[2];
    }
    int l[3] = {(int)t[0].size(), (int)t[1].size(), (int)t[2].size()};
    if (l[0] > n / 2)
      fout << ans - Calc(0) << '\n';
    else if (l[1] > n / 2)
      fout << ans - Calc(1) << '\n';
    else if (l[2] > n / 2)
      fout << ans - Calc(2) << '\n';
    else
      fout << ans << '\n';
    for (int i : {0, 1, 2})
      t[i].clear();
    ans = 0;
  }
  return 0;
}