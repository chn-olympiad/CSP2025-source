#include <bits/stdc++.h>
#define F(i, l, r) for (int i = l; i <= r; i ++)
#define G(i, r, l) for (int i = r; i >= l; i --)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef __int128 i128;

template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }
template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }

const int N = 507, MOD = 998244353;

auto fplus = [](int x, int y) { return x + y < MOD ? x + y : x + y - MOD; };
auto fminus = [](int x, int y) { return x < y ? x - y + MOD : x - y; };
auto Fplus = [](int &x, int y) { x = fplus(x, y); };
auto Fminus = [](int &x, int y) { x = fminus(x, y); };

int read() {
  int x = 0, op = 0;
  char c = getchar();
  while (c < '0' || c > '9')
  	op ^= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
  	x = x * 10 + (c - '0'), c = getchar();
  return x * (op ? -1 : 1);
}

string s;
int n, m, c[N], f[1 << 18][20], dp[N][N], fac[N], sum[N];

void sol1() {
  f[0][0] = 1;
  F(i, 0, (1 << n) - 2)
  	F(j, 0, n) F(k, 1, n)
  	  if (!((i >> k - 1) & 1)) {
  	  	int ppc = __builtin_popcount(i);
  	  	bool fl = (ppc - j < c[k]) && (s[ppc + 1] == '1');
  	  	Fplus(f[i | (1 << k - 1)][j + fl], f[i][j]);
	  }
  int ans = 0;
  F(i, m, n) Fplus(ans, f[(1 << n) - 1][i]);
  cout << ans << '\n';
}
void sol2() {
  dp[0][0] = 1;
  F(i, 1, n) F(j, 0, i - 1) {
  	int cnt = max(0, j - c[i] + 1);
  	Fplus(dp[i][j + 1], (LL) dp[i - 1][j] * cnt % MOD);
  	Fplus(dp[i][j], (LL) dp[i - 1][j] * (i - cnt) % MOD);
  }
  int ans = 0;
  F(i, 0, n - m) Fplus(ans, dp[n][i]);
  cout << ans << '\n';
}
void sol3() {
  int ans = 0;
  fac[0] = 1;
  F(i, 1, n) fac[i] = (LL) fac[i - 1] * i % MOD; 
  F(i, 1, n) sum[c[i]] ++;
  F(i, 1, n) sum[i] += sum[i - 1];
  for (int i = 1, j = 0, k = 1; i <= n; i ++)
    if (s[i] == '1') {
      Fplus(ans, (LL) k * fac[n - j - 1] % MOD * (n - sum[i - 1]) % MOD);
      if (sum[i - 1] < j) {
      	ans = fac[n];
	    break;
	  }
	  k = (LL) k * (sum[i - 1] - (j ++)) % MOD;
	}
  cout << ans << '\n';
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  n = read(), m = read();
  cin >> s, s = ' ' + s;
  F(i, 1, n) c[i] = read();
  sort(c + 1, c + n + 1);
  bool fl = 1;
  F(i, 1, n) fl = fl && (s[i] == '1');
  if (n <= 18) sol1();
  else if (fl) sol2();
  else if (m == 1) sol3();
  else cout << "0\n";
  return 0;
}

