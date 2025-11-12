#include<bits/stdc++.h> // exp:60pts
using namespace std;
typedef long long ll;
constexpr int MOD = 998244353;
constexpr int MAXN = 5000 + 5;
template <typename _Tp>
void read(_Tp &res) {
	res = 0;
	bool f = 0;
	char ch = getchar();
	while (ch < '0' ||  ch > '9')
		f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	res = f ? -res : res;
}
int n;
int len[MAXN];
int total_max_length;
ll frac[MAXN], inv[MAXN];
ll qpow(ll base, int x) {
	ll res = 1;
	while (x) {
		if (x & 1)
			res = res * base % MOD;
		base = base * base % MOD, x >>= 1;
	}
	return res;
}
void init() {
	frac[0] = inv[0] = 1;
	for (int i = 1; i <= 5000; ++i)
		frac[i] = frac[i - 1] * i % MOD, inv[i] = qpow(frac[i], MOD - 2);
}
bool check(int x) {
	if (__builtin_popcount(x) < 3)
		return false;
	ll sum = 0;
	int max_len = 0;
	for (int i = 0; i < n; ++i)
		if ((x >> i) & 1)
			sum += len[i + 1], max_len = max(max_len, len[i + 1]);
//	cout << x << ' ' << sum << ' ' << max_len << '\n';
	return sum > (max_len << 1);
}
void solve1() {
	ll res = 0;
	for (int i = 0; i < (1 << n); ++i)
		if (check(i))
			++res;
	cout << res % MOD;
}
ll C(int m, int n) {
	if (n > m || n < 0 || m <= 0)
		return 0;
	if (n == m || n == 0)
		return 1;
	return (((frac[m] * inv[n]) % MOD) * inv[m - n]) % MOD;
}
void solve2() {
	if (n < 3)
		return cout << 0 << '\n', void();
	long long res = 0;
	for (int i = 3; i <= n; ++i) {
		res += C(n, i);
		while (res >= MOD)
			res -= MOD;
	}
	cout << res;
}
int main() {
#if DEBUG
	freopen(".\\polygon\\polygon3.in", "r", stdin);
	freopen(".\\polygon\\polygon3.out", "w", stdout);
#else
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
	init();
	read(n);
	for (int i = 1; i <= n; ++i)
		read(len[i]), total_max_length = max(total_max_length, len[i]);
	if (n <= 20)
		return solve1(), 0;
	if (total_max_length == 1)
		return solve2(), 0;
	solve1();
	return 0;
}