#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++) 
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define int long long
#define RD read()
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
  while('0' <= ch && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
  return x * f;
}

int const N = 505, P = 998244353;

int n, m;
char a[N];

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);

  int ans = 1;
  cin >> n >> m;
  rep(i, 1, n) ans = ans * i % P;
  printf("%lld\n", ans);

  return 0;
}