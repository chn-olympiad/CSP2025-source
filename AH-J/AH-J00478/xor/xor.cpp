#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int n, k;
int a[500005];
int preXor[500005];
std::unordered_map<int, std::vector<int>> preXorIdexes;
int dpLast[500005];
int dpPreMax[500005];

inline int getXorSum(int left, int right) noexcept {
	return preXor[right] ^ preXor[left - 1];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> k;
	preXorIdexes[0].emplace_back(0);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		preXor[i] = preXor[i - 1] ^ a[i];
		preXorIdexes[preXor[i]].emplace_back(i);
	}

	for (int right = 1; right <= n; ++right) {
		const auto& idexes = preXorIdexes[preXor[right] ^ k];

		int l = 0, r = idexes.size(), last = -1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (idexes[mid] < right) {
				last = mid;
				l = mid + 1;
			} else {
				r = mid;
			}
		}

		// forall 0<=i<=last, [idexes[i] + 1, right] is valiable
		// obviously, we choose [idexes[last]] + 1, right]

		if (last < 0) {
			dpPreMax[right] = dpPreMax[right - 1];
			continue;
		}

		// std::cout << right << " last " << idexes[last] + 1 << std::endl;

		// dpLast[right] = max(dpLast[i] for 0<=i<=idexes[last]) + 1
		dpLast[right] = dpPreMax[idexes[last]] + 1;
		// std::cout << "    " << dpLast[right] << std::endl;
		
		dpPreMax[right] = std::max(dpPreMax[right - 1], dpLast[right]);
	}

	std::cout << *std::max_element(dpLast + 1, dpLast + 1 + n) << std::endl;

	return 0;
}
