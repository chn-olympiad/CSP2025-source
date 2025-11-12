#include <bits/stdc++.h>

#define int int64_t

using namespace std;

constexpr int N = 510, P = 998244353;
int s[N], c[N], p[N], f[20][20][1 << 18 | 10];

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  
  int n, m;
  cin >> n >> m;
  
  string tmp;
  cin >> tmp;
  
  for (int i = 1; i <= n; i++) s[i] = tmp[i - 1] - '0';
  for (int i = 1; i <= n; i++) cin >> c[i];
  
  iota(p + 1, p + n + 1, 1);
  
  int res = 0;
  do {
    int g = 0, l = 0;
    for (int i = 1; i <= n; i++) {
      if (g >= c[p[i]] || !s[i]) g++;
      else l++;
    }
    
    res += l >= m;
  } while (next_permutation(p + 1, p + n + 1));
  
  cout << res;
  
//  f[0][0][0] = 1;
//  for (int i = 1; i <= n; i++) {
//    for (int j = 0; j <= i; j++) {
//      for (int S = 0; S < 1 << n; S++) {
//        if (__builtin_popcountll(S) != i) continue;
//        
//        for (int k = 1; k <= n; k++) {
//          if (!(S & 1 << (k - 1))) continue;
//          
////          cerr << i << ' ' << j << ' ' << (S & 1) << !!(S & 2) << !!(S & 4) << ' ' << k << ": ";
//          
//          if (i - j >= c[k] || !s[i]) {
////            cerr << "cannot pass";
//            if (j) (f[i][j][S] += f[i - 1][j - 1][S ^ (1 << (k - 1))]) %= P; // cerr << ", from " << i - 1 << ' ' << j - 1 << ' ' << (S ^ (1 << (k - 1)));
//          }
//          else {
////            cerr << "pass";
//            (f[i][j][S] += f[i - 1][j][S ^ (1 << (k - 1))]) %= P; // cerr << ", from " << i - 1 << ' ' << j << ' ' << (S ^ (1 << (k - 1)));
//          }
//          
////          cerr << '\n';
//        }
//      }
//    }
//  }
//  
////  for (int i = 1; i <= n; i++)
////    for (int j = 0; j <= i; j++)
////      for (int S = 0; S < 1 << n; S++)
////        if (__builtin_popcountll(S) == i)
////          cerr << i << ' ' << j << ' ' << (S & 1) << !!(S & 2) << !!(S & 4) << ": " << f[i][j][S] << '\n';
//  
//  int res = 0;
//  for (int i = m; i <= n; i++) (res += f[n][i][(1 << n) - 1]) %= P;
//  
//  cout << res;
}
