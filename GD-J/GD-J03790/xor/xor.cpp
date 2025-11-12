#include <iostream>

int n, k, a[114514], ans;

int XOR(int l, int r) {
	int to = a[l];
	if (l == r) return to;
	for (int i = l + 1 ; i <= r ; ++i) to = to xor a[i];
	return to;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	std::cin >> n >> k;
	for (int i = 0 ; i < n ; ++i)
		std::cin >> a[i];
	
	for (int l = 0 ; l < n ; ++l)
		for (int r = l ; r < n ; ++r) {
			int sum = XOR(l, r);
			if (sum == k) {
			       	l = r = r + 1, ++ans;
				break;
			}
		}

	std::cout << ans << std::endl;

	fclose(stdin);
	fclose(stdout);
}
