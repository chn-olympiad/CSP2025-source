/*
g++ -Wall -O2 -std=c++14 -static polygon.cpp -o polygon && ./polygon
*/
#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> a;
constexpr int MOD = 998244353;
vector<map<tuple<int, int>, int>> mem;
int dfs(int lst, int maxa, int sum) {
  if (lst == n) return 0;
  if (mem[lst].count({maxa, sum}))
    return mem[lst][{maxa, sum}];
  int res = 0;
  for (int i = lst + 1; i <= n; i++) {
    int nmaxa = max(maxa, a[i]), nsum = sum + a[i];
    if (nsum > 2 * nmaxa) {
      res = (res + 1) % MOD;
    }
    res = (res + dfs(i, nmaxa, nsum)) % MOD;
  }
  mem[lst][{maxa, sum}] = res;
  return res;
}
signed main() {
  freopen("polygon.in", "r", stdin);
  // freopen("polygon3.in", "r", stdin); ////
  freopen("polygon.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n + 1);
  mem.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << dfs(0, 0, 0) << '\n';
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> a, ps;
// constexpr int MOD = 998244353;
// signed main() {
//   freopen("polygon4.in", "r", stdin);
//   freopen("polygon.out", "w", stdout);
//   ios::sync_with_stdio(0), cin.tie(0);
//   cin >> n;
//   a.resize(n + 1);
//   ps.resize(n + 1);
//   for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//     ps[i] = ps[i - 1] + a[i];
//   }
//   vector<vector<map<int, int>>> dp(n + 1, vector<map<int, int>>(5005));
//   // dp[i][j][k] fangshi
//   // i <i
//   // j maxa
//   // k sum
//   for (int i = 1; i <= n; i++) {

//   }
// }