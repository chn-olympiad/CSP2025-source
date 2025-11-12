#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int n, m, a[X], K, rnk;

int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  cfor (i, 1, n * m) cin >> a[i];
  K = a[1];
  sort(a + 1, a + n * m + 1, greater<int>());
  cfor (i, 1, n * m)
    if (a[i] == K)
      rnk = i;
  
  int x = (rnk - 1) / n + 1, y = (rnk - 1) % (2 * n) + 1;
  if (y > n) y = 2 * n - y + 1;
  cout << x << " " << y;
  return 0;
}