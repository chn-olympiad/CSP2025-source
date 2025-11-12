#include <bits/stdc++.h>
#define F(i, l, r) for (int i = l; i <= r; i ++)
#define G(i, r, l) for (int i = r; i >= l; i --)
using namespace std;

template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }
template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }

const int N = 1e5 + 7;

int read() {
  int x = 0, op = 0;
  char c = getchar();
  while (c < '0' || c > '9')
  	op ^= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
  	x = x * 10 + (c - '0'), c = getchar();
  return x * (op ? -1 : 1);
}

int n, a[N][3], pos[N][3], cnt[3], ans, id, dlt[N];

void solve() {
  id = -1, ans = 0;
  F(i, 0, 2) cnt[i] = 0;
  n = read();
  F(i, 1, n) {
  	int opt = 0;
  	F(j, 0, 2) {
  	  a[i][j] = read();
  	  if (a[i][j] > a[i][opt]) opt = j;
	}
	ans += a[i][opt]; 
	pos[++ cnt[opt]][opt] = i;
  }
  F(i, 0, 2) if (cnt[i] > n / 2) id = i;
  if (id == -1) return cout << ans << '\n', void();
  F(i, 1, cnt[id]) {
  	int mn = 1e9;
  	F(j, 0, 2) if (j != id)
  	  Fmin(mn, a[pos[i][id]][id] - a[pos[i][id]][j]);
  	dlt[i] = mn;
  }
  sort(dlt + 1, dlt + cnt[id] + 1);
  F(i, 1, cnt[id] - n / 2) ans -= dlt[i];
  cout << ans << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int T = read();
  while (T --) solve();
  return 0;
}

