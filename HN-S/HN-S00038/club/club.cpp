#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int N = 1e5 + 3, C = 2e4 + 3;

struct Node {
  int a, b, c, w; // a, b, c is number, w is better
  bool operator< (const Node &p) const {
    return w < p.w;
  }
};

int a[5], cnt[C][5];

Node c;

int t, ans, n;

void G(Node &p) {
  int ma = max(p.a, max(p.b, p.c)), mi = min(p.a, min(p.b, p.c));
  ans += ma;
  p.w = ma - (p.a + p.b + p.c - ma - min(p.a, min(p.b, p.c)));
  if (p.a == ma) a[1]++, cnt[p.w][1]++;
  else if (p.b == ma) a[2]++, cnt[p.w][2]++;
  else if (p.c == ma) a[3]++, cnt[p.w][3]++;
  return ;
}

void H(int p) {
  for (int i = a[p] - n / 2, j = 0; i > 0 && j < C; j++) {
    if (cnt[j][p] >= i) ans -= i * j, i = 0;
    else ans -= cnt[j][p] * j, i -= cnt[j][p];
  }
}

void Solve() {
  int p, ma, mi;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &c.a, &c.b, &c.c);
    ma = max(c.a, max(c.b, c.c)), mi = min(c.a, min(c.b, c.c));
    ans += ma;
    c.w = ma - (c.a + c.b + c.c - ma - min(c.a, min(c.b, c.c)));
    if (c.a == ma) a[1]++, cnt[c.w][1]++;
    else if (c.b == ma) a[2]++, cnt[c.w][2]++;
    else if (c.c == ma) a[3]++, cnt[c.w][3]++;
  }
  if (a[1] <= n / 2 && a[2] <= n / 2 && a[3] <= n / 2) {
    printf("%d\n", ans);
    return ;
  }
   p = max(a[1], max(a[2], a[3]));
   if (p == a[1]) H(1);
   else if (p == a[2]) H(2);
   else if (p == a[3]) H(3);
    printf("%d\n", ans);
   return ;
}

void Clear() {
  a[1] = a[2] = a[3] = 0, ans = 0;
  for (int i = 0; i <= C - 3; i++) {
    cnt[i][1] = cnt[i][2] = cnt[i][3] = 0;
  }
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  scanf("%d", &t);
  while (t--) {
    Clear();
    Solve();
  }
  return 0;
}
