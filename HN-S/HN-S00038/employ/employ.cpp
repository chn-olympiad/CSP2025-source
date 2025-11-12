#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int N = 5e2 + 3, mod = 998244353;

int n, m, p;

string s;

int a[N];

bool f[N];

int dfs(int k, int p) {
  int ans = 0;
  if (k == n) return (p >= m);
  for (int j = 0; j < n; j++) {
    if (f[j]) continue;
    f[j] = 1;
    ans = (ans + dfs(k + 1, p + (k - p >= a[j] || s[k] == '0' ? 0 : 1))) % mod;
    f[j] = 0;
  }
  return ans;
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << dfs(0, 0);
  return 0;
}
