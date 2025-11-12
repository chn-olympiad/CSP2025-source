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

int const N = 1e5 + 5;

int n;
struct node { int x, y, z, d; } a[N], b[N];
bool cmp(node a, node b) { return a.d > b.d; }
int c[N][3];
/*
0 : <
1 : >
2 : =
*/

int solve() {
  rep(i, 1, n) a[i].d = max(a[i].x, a[i].y) - a[i].z;
  
  int now = 0;
  rep(i, 1, n) now += a[i].z;
  sort(a + 1, a + 1 + n, cmp);
  rep(i, 1, n) {
    rep(j, 0, 2) c[i][j] = c[i - 1][j];
    if(a[i].x > a[i].y) c[i][0] ++;
    else if(a[i].x < a[i].y) c[i][1] ++;
    else c[i][2] ++;
  }
  
  int ans = 0;
  rep(i, 1, n) {
    now += a[i].d;
    if(i < n / 2) continue;
    int c0 = c[i][0], c1 = c[i][1], c2 = c[i][2];
    if(c0 < c1) c0 += min(c2, c1 - c0), c2 -= min(c2, c1 - c0);
    else c1 += min(c2, c0 - c1), c2 -= min(c2, c0 - c1);
    if(c2) c0 += c2 / 2, c1 += c2 / 2, c2 = c2 % 2;
    c1 += c2;
    if(max(c0, c1) > n / 2) continue;
    ans = max(ans, now);
  } return ans;
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  int T = RD;

  while(T --) {
    n = RD;
    // cerr << "pass\n";
    rep(i, 1, n) b[i].x = RD, b[i].y = RD, b[i].z = RD;

    int ans = 0;
    rep(i, 1, n) a[i] = b[i];
    int res = solve();
    ans = max(ans, res);
    // printf("res = %lld\n", res);
    
    rep(i, 1, n) a[i].x = b[i].x, a[i].y = b[i].z, a[i].z = b[i].y;
    res = solve();
    ans = max(ans, res);
    // printf("res = %lld\n", res);

    rep(i, 1, n) a[i].x = b[i].y, a[i].y = b[i].z, a[i].z = b[i].x;
    res = solve();
    ans = max(ans, res);
    // printf("res = %lld\n", res);

    printf("%lld\n", ans);
  }

  return 0;
}