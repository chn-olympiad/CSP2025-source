#include <bits/stdc++.h>

int pre_xor[500010], nums[500010], N, K, now = 0, ans = 0;

int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	std::cin >> N >> K;
	for (int i = 1; i <= N; i ++) std::cin >> nums[i], pre_xor[i] = pre_xor[i - 1] ^ nums[i];
	
	for (int i = 1; i <= N; i ++)
		for (int j = now; j < i; j ++)
			if ((pre_xor[i] ^ pre_xor[j]) == K) {
				now = i, ans ++;
				break;
			}
			
	std::cout << ans;
	return 0;
}
