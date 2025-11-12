#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mp make_pair
#define pii pair<int, int>
#define N (int)1e3 + 10

namespace orzgcx {
  int n, a[N], b[N], c[N], dp[500][500][500];

  void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }
    int W = n / 2;
    
    if (n == 2) {
      int MAXN = 0;
      MAXN = max(MAXN, max(a[1] + b[2], a[1] + b[3]));
      MAXN = max(MAXN, max(b[1] + a[2], b[1] + b[3]));
      MAXN = max(MAXN, max(c[1] + a[2], c[1] + b[3]));

      cout << MAXN << endl;
    } else {
    	sort(a + 1, a + n + 1);
    	sort(b + 1, b + n + 1);
    	sort(c + 1, c + n + 1);
    	cout << a[n] + b[n] + c[n] + a[n - 1] + b[n - 1] + c[n - 1] << endl;
		}
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);

  freopen("club.in", "r", stdin); 
  freopen("club.out", "w", stdout);

  int t = 1;
  cin >> t;
  while (t--) {
    orzgcx::solve();
  }
    
  return 0;
}
