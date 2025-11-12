#include <iostream>
#include <vector>
#include <algorithm>

constexpr long long MOD = 998244353ll;

int n;
long long a[10000];
long long preSum[10000];

std::vector<long long> sums;
long long ans;

long long tree[100005];

int lowbit(int n) {
        return n & -n;
}

void edit(int idex, long long v) {
        for (int i = idex; i <= n; i += lowbit(i)) {
                tree[i] += v;
		tree[i] %= MOD;
        }
}

long long query(int idex) {
        long long ans = 0;
        for (int i = idex; i >= 1; i -= lowbit(i)) {
                ans += tree[i];
		ans %= MOD;
        }
        return ans;
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		preSum[i] = preSum[i - 1] + a[i];
	}

	std::sort(a + 1, a + 1 + n);
	sums.resize(preSum[n] + 5, 0ll);
	sums[0] = 1;

	for (int i = 1; i <= n; ++i) {
		if (i >= 3) {
			long long newAns = 0;
			for (int j = a[i] + 1; j <= preSum[i - 1]; ++j) {
				newAns += sums[j];
				newAns %= MOD;
			}

			// std::cout << "add " << newAns << std::endl;
			ans += newAns;
			ans %= MOD;
		}

		for (int j = preSum[i - 1]; j >= 0; --j) {
			sums[j + a[i]] += sums[j];
			sums[j + a[i]] %= MOD;
		}

		// for (int j = 1; j <= preSum[i - 1] + a[i]; ++j) {
		// 	std::cout << sums[j] << " ";
		/// }
		// std::cout << std::endl;
		
		// sums idex [0, presum[i]]
	}

	std::cout << ans << std::endl;

	return 0;
}
