#include <bits/stdc++.h>
using namespace std;

const int mod =  998244353;
const int maxn = 5050;

int a[maxn], n, ans;
int pre_sum[maxn], pre_mx[maxn];

int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
	std::ios::sync_with_stdio (false);
	std::cin.tie (nullptr);
	std::cout.tie (nullptr);
	
	std::cin >> n;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		pre_sum[i] = pre_sum[i - 1] + a[i];
		pre_mx[i] = std::max (pre_mx[i - 1], a[i]);
	}
	
	if (n == 0 || n == 1 || n == 2) {
		std::cout << 0 << "\n";
		return 0;
	}
	
	if (n == 3) {
		int k = std::max (a[1], std::max (a[2], a[3]) );
		int p = a[1] + a[2] + a[3];
		if (p > 2 * k) std::cout << 1 << "\n";
		else std::cout << 0 << "\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 2; j <= n; j ++) {
			int step_sum = pre_sum[j] - pre_sum[i - 1];
			int step_max = std::max (pre_mx[i], pre_mx[j]);
			
			if (step_sum > 2 * step_max) {
				ans ++;
				ans = ans % mod;
			}
		}
	}
	
	std::cout << ans * 2 << "\n";
	return 0;
}
