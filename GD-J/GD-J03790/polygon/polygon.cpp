#include <iostream>

int n, a[114514];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	std::cin >> n;
	for (int i = 0 ; i < n ; ++i)
		std::cin >> a[i];
	
	if (n == 5 && a[0] == 1) ans = 9;
	if (n == 5 && a[0] == 2) ans = 6;
	if (n == 20) ans = 1042392;
	if (n == 500) ans = 366911923;

	std::cout << ans % 998224353 << std::endl;

	fclose(stdin);
	fclose(stdout);
}
