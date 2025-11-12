#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 1e5 + 5;

int n, k, sum;
int a[MAXN];
int pre[MAXN];
int ans = 0;
int min_ = -1;

int get_res(int l, int r) {
	return pre[r] ^ pre[l - 1];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pre[i] = a[i] ^ pre[i - 1];
	}
	for (int j = 1; j <= n; j++) {
		for (int i = min_ + 1; i <= j; i++) {
			if (i > min_) {
				if (get_res(i, j) == k) {
					min_ = j;
					ans++;
				}
			}
		}
	}
//	std::sort(vec.begin(), vec.end(), cmp);
//	for (int i = 0; i < vec.size(); i++) {
//		if (vec[i].first > min_) {
////			std::cout << vec[i].first << ' ' << vec[i].second << std::endl;
//			min_ = vec[i].second;
//			ans++;
//		}
//	}
	std::cout << ans;
	return 0;
}

