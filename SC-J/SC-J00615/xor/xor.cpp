#include<bits/stdc++.h> // exp : 25pts
using namespace std;
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
int n, k;
constexpr int MAXN = 5e5 + 5;
constexpr int LOG = 22;
int sum[MAXN][LOG];
int a[MAXN];
int vst[MAXN];
int zz[MAXN];
bool flag1 = 1, flag2 = 1;
void solve1() {
	cout << n / 2;
}
void solve2() {
	int res = 0;
	if (k == 0) {
		for (int i = 1; i <= n; ++i)
			if (a[i] && a[i + 1])
				++res, ++i;
			else
				++res;
	} else
		for (int i = 1; i <= n; ++i)
			if (a[i])
				++res;
	cout << res;
}
int main() {
#if DEBUG
	freopen(".\\xor\\xor6.in", "r", stdin);
	freopen(".\\xor\\xor6.out", "w", stdout);
#else
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
#endif
	read(n), read(k);
	for (int i = 0; i < LOG; ++i)
		zz[i] = ((k >> 1) & 1);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		if (a[i] > 1)
			flag1 = flag2 = 0;
		if (a[i] != 1)
			flag2 = 0;
		for (int j = 0; j < LOG; ++j)
			sum[i][j] = (sum[i - 1][j] + ((a[i] >> i) & 1)) % 2;
	}
	if (flag2)
		return solve1(), 0;
	else if (flag1)
		return solve2(), 0;
	int res = 0;
	for (int l = 1; l <= n; ++l)
		for (int len = 1;  len <= n - l; ++len) {
			int r = l + len;
			for (int i = 0; i < LOG; ++i)
				if ((sum[r][i] - sum[l - 1][i] + 2) % 2 != zz[i] || vst[i])
					goto end;
			for (int i = l; i <= r; ++i)
				vst[i] = 1;
			++res;
			end:
			res = res;
		}
	cout << res;
	return 0;
}