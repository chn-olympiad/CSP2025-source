#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 1e5 + 5;

int T, n;
int a[kN][3];
vector<int> v[3];
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> T; T--;) {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int d = 0; d < 3; d++)
        cin >> a[i][d];
      int mx = max_element(a[i], a[i] + 3) - a[i];
      sort(a[i], a[i] + 3, greater<int>());
      ans += a[i][0];
      v[mx].push_back(a[i][0] - a[i][1]);
    }
    sort(v, v + 3, [&](vector<int> &p, vector<int> &q) { return p.size() > q.size(); });
    if (v[0].size() > n / 2) {
      sort(v[0].begin(), v[0].end());
      for (int i = 0; i < v[0].size() - n / 2; i++)
        ans -= v[0][i];
    }
    cout << ans << '\n';
    
    for (int i = 0; i < 3; i++)
      v[i].clear();
  }
  return 0;
}