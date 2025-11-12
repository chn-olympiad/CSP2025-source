#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
const int mod = 998244353;
int a[N];
int ans = 0;
int n;
void dfs(int start, int maxn, int sum) {
  if (sum > 2 * maxn) {
    ans ++;
    ans %= mod;
  }
  if (n - start == 1 && sum + a[n] < 2 * maxn){
    return;
  }
  for (int i = start; i <= n; i ++) {
    dfs(i + 1, max(a[i], maxn), sum + a[i]);
  }
  return;
}
int main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
  }
  dfs(1, 0, 0);
  cout << ans << endl;
  return 0;
}