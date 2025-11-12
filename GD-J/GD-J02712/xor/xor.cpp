#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 2e6 + 10;

int n, k, a[N], p[N], last[M], r, ans;

int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] ^ a[i];
    int bu = p[i] ^ k;
    // cout << i << " " << p[i] << " " << bu << " " << last[bu] << endl;
    if (a[i] == k) {
      r = i;
      ans++;
    }
    if ((last[bu] || bu == 0) && r <= last[bu]) {
      r = i;
      ans++;
      // cout << r << " " << last[bu] << endl;
    }
    last[p[i]] = i;
  }
  cout << ans;
  return 0;
}