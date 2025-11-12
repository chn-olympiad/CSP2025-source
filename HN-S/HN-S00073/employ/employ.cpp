#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 505, M = 998244353; 
LL n, m, c[N], p[N], w;
string s;
int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s, s = " " + s;
  for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
  do {
    int k = 0;
    for (int i = 1; i <= n; i++)
      i - 1 - k < c[p[i]] && (k += s[i] - '0'); 
    w += k >= m;
  } while(next_permutation(p + 1, p + n + 1));
  cout << w;
  return 0;
}
/*
没时间了，最后 20分钟赶紧写一个 8分的

检查前面的题去 
*/
