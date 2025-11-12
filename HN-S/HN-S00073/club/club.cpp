#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int, int>;
using Arr = array<int, 3>;
const int N = 1e5 + 5;
int t, n, a[N][3], c[3];
Pii x[3];
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> t; t; t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i][0] >> a[i][1] >> a[i][2];
    priority_queue<Arr, vector<Arr>, greater<Arr>> q[3];
    int s = c[0] = c[1] = c[2] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) x[j] = {a[i][j], j};
      sort(x, x + 3, greater<Pii>());
      int p = x[0].second, w = x[0].first - max(x[1].first, x[2].first);
      if (c[p] < n / 2) {
        q[p].push({w, i, x[0].first}), c[p]++;
      } else if (w > q[p].top()[0]) {
        Pii v[3];
        for (int j = 0; j < 3; j++) v[j] = {a[q[p].top()[1]][j], j};
        sort(v, v + 3, greater<Pii>());
        c[v[1].second]++;
        q[v[1].second].push({0, q[p].top()[1], v[1].first});
        q[p].pop(), q[p].push({w, i, x[0].first});
      } else {
        c[x[1].second]++;
        q[x[1].second].push({0, i, x[1].first});
      }
    }
    for (int i = 0; i < 3; i++)
      for (; q[i].size(); q[i].pop()) s += q[i].top()[2];
    cout << s << "\n";
  }
  return 0;
}
/*
想到一个贪心做法

错了，从来没有想过 T1这么难 

发现可以直接反贪，不过看起来有点小复杂 

很快写出代码，大样例都过了 

CCF保佑我 AC吧 
*/
