/*
 * @file
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

constexpr int N = 2e5 + 5;

std::string s1, s2;
std::string t1, t2;
int bef1[N], af1[N];
int bef2[N], af2[N];
int bet1, aft1;
int bet2, aft2;

int main() {
	#ifndef DEBUG
	file(replace);
	#endif

	int n, q;
	n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		std::cin >> s1 >> s2;
		int sz = s1.size();
		int j = 0;
		for (; j < sz; j++) {
			if (s1[j] == 'b') {
				break;
			}
		}
		bef1[i] = j, af1[i] = n - j - 1;
		j = 0, sz = s2.size();
		for (; j < sz; j++) {
			if (s2[j] == 'b') {
				break;
			}
		}
		bef2[i] = j, af2[i] = n - j - 1;
	}
	for (int i = 1; i <= q; i++) {
		int cnt = 0;
		std::cin >> t1 >> t2;
		int sz = t1.size();
		int j = 0;
		for (; j < sz; j++) {
			if (t1[j] == 'b') {
				break;
			}
		}
		bet1 = j, aft1 = n - j - 1;
		j = 0, sz = t2.size();
		for (; j < sz; j++) {
			if (t2[j] == 'b') {
				break;
			}
		}
		bet2 = j, aft2 = n - j - 1;
		for (int i = 1; i <= n; i++) {
			if (bef1[i] > bet1 || af1[i] > aft1 || bef2[i] > bet2 || af2[i] > aft2) {
				continue;
				// printf("111");
			}
			if (bef2[i] - bef1[i] == bet2 - bet1 && af2[i] - af1[i] == aft2 - aft1) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}