#include <cstdio>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXSZ = 1 << 20;
char ch, buf[MAXSZ], *p1, *p2;
#define ge() (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, MAXSZ, stdin), p1 == p2) ? EOF : *p1++)
template <typename T_T>
inline void read(T_T &x) {
	x = 0;
	
	while (ch < '0' || '9' < ch) ch = ge();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ge();
	}
}
template <typename T_T>
inline void write(T_T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48);
}
template <typename T_T>
inline T_T max(T_T a, T_T b) {return a > b ? a : b;}
inline ll ksm(ll a, int b, int p) {
	ll sum = 1;
	
	while (b) {
		if (b & 1) sum = sum * a % p;
		
		a = a * a % p;
		b >>= 1;
	}
	
	return sum;
}

const int N = 5005, mod = 998244353;
int n, a[N];
ll fact[N], inv_fact[N], ans;
void init() {
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
	inv_fact[n] = ksm(fact[n], mod - 2, mod);
	for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fact[n] * inv_fact[m] % mod * inv_fact[n - m] % mod;
}

void dfs(int step, int maxn, int cnt, int sum) {
	if (step > n) {
		if (cnt > 2 && maxn * 2 < sum) ans = (ans + 1) % mod;
		return ;
	}
	
	dfs(step + 1, max(maxn, a[step]), cnt + 1, sum + a[step]);
	dfs(step + 1, maxn, cnt, sum);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
		
	if (n <= 20) {
		dfs(1, 0, 0, 0);
		write(ans), putchar('\n');
		
		fclose(stdin), fclose(stdout);
		return 0;
	}
	
	init();
	for (int len = 3; len <= n; len++)
		ans = (ans + C(n, len)) % mod;
	write(ans >> 1), putchar('\n');
	
	fclose(stdin), fclose(stdout);
	return 0;
}