#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("road.in", "w", stdout);
  int n = 1e4, m = 1e6, k = 10;
  cout << n << " " << m << " " << k << "\n";
  for (int i = 2; i <= n; i++) {
    cout << i - 1 << " " << i << " " << 1 << "\n";
  }
  for (int i = n; i <= m; i++) {
    int u = rand() % n + 1, v = rand() % n + 1;
    cout << u << " " << v << " " << 1 << "\n";
  }
  for (int i = 1; i <= k; i++) {
    cout << 1 << " ";
    for (int j = 1; j <= n; j++) {
      cout << 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}