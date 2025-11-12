/*
 * @file club.cpp
 * @author HN-S00799
*/
#include <bits/stdc++.h>
#define file(s) \
	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)

using i64 = long long;
using ull = unsigned long long;
using i28 = __int128;
using f32 = double;
using ldb = long double;

inline int read() {
	register int x = 0, sgn = 1;
	register char ch = getchar_unlocked();
	while(!isdigit(ch)) {
		if (ch == '-') {
			sgn = -1;
		}
		ch = getchar_unlocked();
	}
	while (isdigit(ch)) {
		x *= 10;
		x += ch - '0';
		ch = getchar_unlocked();
	}
	return x * sgn;
}

constexpr int N = 1e5 + 5;
struct stu{
	int a, b, c;
	char maxtype;
	int loss;
}a[N];

bool cmp(stu x, stu y) {
	return x.loss < y.loss;
}


void work() {
	// 读入 + 预处理
	memset(a, 0, sizeof(a));
	int n = read();
	int ca = 0, cb = 0, cc = 0;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i].a = read(), a[i].b = read(), a[i].c = read();
		// printf("a = %d, b = %d, c = %d.\n", a[i].a, a[i].b, a[i].c);
		if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
			ans += a[i].a;
			ca++;
			a[i].maxtype = 'A';
			if (a[i].b >= a[i].c) {
				a[i].loss = a[i].a - a[i].b;
			} else {
				a[i].loss = a[i].a - a[i].c;
			}
			// printf("tp = %c, ls = %d\n", a[i].maxtype, a[i].loss);
		} else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
			ans += a[i].b;
			cb++;
			a[i].maxtype = 'B';
			if (a[i].a >= a[i].c) {
				a[i].loss = a[i].b - a[i].a;
			} else {
				a[i].loss = a[i].b - a[i].c;
			}
			// printf("tp = %c, ls = %d\n", a[i].maxtype, a[i].loss);
		} else {
			ans += a[i].c;
			cc++;
			a[i].maxtype = 'C';
			if (a[i].a >= a[i].b) {
				a[i].loss = a[i].c - a[i].a;
			} else {
				a[i].loss = a[i].c - a[i].b;
			}
			// printf("tp = %c, ls = %d\n", a[i].maxtype, a[i].loss);
		}
	}

	// 没有多人
	if (ca <= (n >> 1) && cb <= (n >> 1) && cc <= (n >> 1)) {
		printf("%lld\n", ans);
		return ;
	}

	

	// 多了人，开始贪
	if (ca > (n >> 1)) {
		// printf("A!\n");
		// A 组多了
		std::sort(a + 1, a + 1 + n, cmp);
		for (int i = 1, j = 1; i <= n && j <= ca - (n >> 1); i++) {
			// printf("%c\n", a[i].maxtype);
			if (a[i].maxtype == 'A'){
				// printf("j:%d\n", j);
				ans -= a[i].loss;
				j++;
			}
		}
	} else if (cb > (n >> 1)) {
		// printf("B!\n");
		// B 组多了
		std::sort(a + 1, a + 1 + n, cmp);
		for (int i = 1, j = 1; (i <= n && j <= (cb - (n >> 1))); i++) {
			// printf("%c\n", a[i].maxtype);
			if (a[i].maxtype == 'B'){
				// printf("j:%d\n", j);
				ans -= a[i].loss;
				j++;
			}
		}
	} else {
		// printf("C!\n");
		// C 组多了
		std::sort(a + 1, a + 1 + n, cmp);
		for (int i = 1, j = 1; i <= n && j <= cc - (n >> 1); i++) {
			// printf("%c\n", a[i].maxtype);
			if (a[i].maxtype == 'C'){
				// printf("j:%d\n", j);
				ans -= a[i].loss;
				j++;
			}
		}
	}

	printf("%lld\n", ans);

	return ;
}

int main() {
	#ifndef DEBUG
	file(club);
	#endif

	int t = read();
	while (t--) {
		work();
	}

	return 0;
}