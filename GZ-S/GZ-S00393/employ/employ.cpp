//GZ-S00393 蒋晨阳 遵义市第四中学
#include <bits/stdc++.h>
using d32 = int;
using u32 = unsigned;
using d64 = long long;
using u64 = unsigned long long;
#define a2pow32(x)	(31 - __builtin_clz(x))
u32 n, m;
char s[501];
u32 c[500];
bool vis[500];
u32 dfs(u32 i, u32 got) {
	if (i >= n && got >= m)	return 1u;
	u32 ans = 0;
	for (u32 j = 0; j != n; ++j) {
		if (vis[j])	continue;
		vis[j] = 1;
		ans += dfs(i + 1, got + (s[i] != '0' && i - got < c[j]));
		vis[j] = 0;
	}
	return ans;
}
int main() {
#ifndef _0x3C17_
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin.tie(0)->sync_with_stdio(0);
#endif
	std::cin >> n >> m >> s;
	for (u32 i = 0; i < n; ++i)	std::cin >> c[i];
	if (n <= 12) {
		std::cout << dfs(0, 0) << '\n';
		return 0;
	}
	return 0;
}
