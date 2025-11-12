#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;

struct Node {
  int i, j, k;
  bool operator>(const Node &oth) const {
    return i > oth.i;
  }
} a[MAXN], b[MAXN << 1];

int n;
bool ch[MAXN];

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].i >> a[i].j >> a[i].k;
  }
  int sum1 = 0;
  for (int i = 1; i <= n; i++) {
    b[(i << 1) - 1] = {a[i].j - a[i].i, i, 0};
    b[i << 1] = {a[i].k - a[i].i, i, 1};
    sum1 += a[i].i;
  }
  sort(b + 1, b + (n << 1) + 1, greater<Node>());
  fill(ch + 1, ch + n + 1, 0);
  int c[] = {0, 0};
  for (int i = 1; i <= n << 1; i++) {
    if (b[i].i < 0 && c[0] + c[1] >= (n >> 1)) break;
    if (c[b[i].k] < (n >> 1) && !ch[b[i].j]) {
      c[b[i].k]++, ch[b[i].j] = 1;
      sum1 += b[i].i;
    }
  }
  int sum2 = 0;
  for (int i = 1; i <= n; i++) {
    b[(i << 1) - 1] = {a[i].i - a[i].j, i, 0};
    b[i << 1] = {a[i].k - a[i].j, i, 1};
    sum2 += a[i].j;
  }
  sort(b + 1, b + (n << 1) + 1, greater<Node>());
  fill(ch + 1, ch + n + 1, 0);
  c[0] = c[1] = 0;
  for (int i = 1; i <= n << 1; i++) {
    if (b[i].i < 0 && c[0] + c[1] >= (n >> 1)) break;
    if (c[b[i].k] < (n >> 1 && !ch[b[i].j])) {
      c[b[i].k]++, ch[b[i].j] = 1;
      sum2 += b[i].i;
    }
  }
  int sum3 = 0;
  for (int i = 1; i <= n; i++) {
    b[(i << 1) - 1] = {a[i].i - a[i].k, i, 0};
    b[i << 1] = {a[i].j - a[i].k, i, 1};
    sum3 += a[i].k;
  }
  sort(b + 1, b + (n << 1) + 1, greater<Node>());
  fill(ch + 1, ch + n + 1, 0);
  c[0] = c[1] = 0;
  for (int i = 1; i <= n << 1; i++) {
    if (b[i].i < 0 && c[0] + c[1] >= (n >> 1)) break;
    if (c[b[i].k] < (n >> 1) && !ch[b[i].j]) {
      c[b[i].k]++, ch[b[i].j] = 1;
      sum3 += b[i].i;
    }
  }
  cout << max({sum1, sum2, sum3}) << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}

