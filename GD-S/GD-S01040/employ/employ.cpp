#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstdio>
#define endl '\n'
using namespace std;
namespace IO {
	inline int Read() {
		int x = 0, k = 0; char ch = getchar();
		while (!isdigit(ch)) k |= (ch == '-'), ch = getchar();
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
		return k ? -x : x;
	}
}
const int MaxN = 5E2 + 10;
const int Mod = 998244353;
int m, n, ans;
int c[MaxN], p[MaxN];
bool s[MaxN];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = IO::Read(), m = IO::Read();
	for (register int i = 1; i <= n; i++) {
		char ch = getchar();
		while (!isdigit(ch)) ch = getchar();
		s[i] = ch ^ '0';
	}
	for (register int i = 1; i <= n; i++) c[i] = IO::Read();
	for (register int i = 1; i <= n; i++) p[i] = i;
	do {
		int cnt = 0, tot = 0;
		for (register int i = 1; i <= n; i++) {
			if (!s[i]) { cnt++; continue; }
			if (cnt < c[p[i]]) tot++;
			else cnt++;
			if (tot == m) break;
		}
		ans = (ans + (tot == m)) % Mod;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
	return 0;
}

