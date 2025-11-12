#include <algorithm>
#include <iostream>

int n, ans;
int a[5005];

void func(int idx, int max_, int sum, int cnt) {
	if (idx > n) {
		return;
	}
	// 选当前的
	int nmax = std::max(max_, a[idx]);
	int nsum = sum + a[idx];
	int ncnt = cnt + 1;
	if (ncnt >= 3 && nsum > 2 * nmax) {
		ans++;
	}
	func(idx + 1, nmax, nsum, ncnt);
	// 不选
	func(idx + 1, max_, sum, cnt);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	} 
//	std::sort(a + 1, a + 1 + n);
	func(1, 0, 0, 0);
	std::cout << ans;
	return 0; 
} 
