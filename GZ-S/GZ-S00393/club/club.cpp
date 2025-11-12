//GZ-S00393 蒋晨阳 遵义市第四中学 
#include <bits/stdc++.h>
using d32 = int;
using u32 = unsigned;
using d64 = long long;
using u64 = unsigned long long;
#define a2pow32(x)	(31 - __builtin_clz(x))
int main() {
#ifndef _0x3C17_
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::cin.tie(0)->sync_with_stdio(0);
#endif
	u32 t;
	std::cin >> t;
	while (t--) {
		constexpr u32 N = 100000;
		u32 n, arr[N][3], cnt[3] = {}, sel[N], ans = 0;
		std::cin >> n;
		for (u32 i = 0; i != n; ++i) {
			std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			u32 t = arr[i][0] < arr[i][1] ? 1 : 0;
			if (arr[i][t] < arr[i][2])	t = 2;
			cnt[t]++;
			ans += arr[i][t];
			sel[i] = t;
		}
		u32 t = cnt[0] < cnt[1] ? 1 : 0;
		if (cnt[t] < cnt[2])	t = 2;
		u32 que[N];
		for (u32 i = 0; i != n; ++i) {
			que[i] = t ? 0 : 1;
			for (u32 j = 0; j != 3; ++j)
				if (j != t && arr[i][que[i]] < arr[i][j])	que[i] = j;
			que[i] = sel[i] != t ? 0x3FFFFFFFF :
			arr[i][sel[i]] - arr[i][que[i]];
		}
		u32 m = std::max(cnt[t], n / 2) - n / 2;
		if (m) {
			std::partial_sort(que, que + n, que + m);
			for (u32 i = 0; i != m; ++i)	ans -= que[i];
		}
		std::cout << ans << '\n';
	}
	return 0;
}
