#include <bits/stdc++.h>

using namespace std;

constexpr int N = 20;
int a[N * N], b[N][N];

signed main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++) cin >> a[i];
  
  int tar = a[1];
  
  sort(a + 1, a + n * m + 1, greater<int>());
  
  for (int i = 1, idx = 1; i <= m; i += 2) {
    for (int j = 1; j <= n; j++) b[j][i] = a[idx++];
    
    if (i + 1 <= m) {
      for (int j = n; j >= 1; j--) b[j][i + 1] = a[idx++];
    }
  }
  
//  for (int i = 1; i <= n; i++)
//    for (int j = 1; j <= m; j++)
//      cout << b[i][j] << " \n"[j == m];
  
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[j][i] == tar) cout << i << ' ' << j;
    }
  }
}
