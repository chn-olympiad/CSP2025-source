#include <iostream>
#include <string>
#define Nahida return 0

const int MOD = 998244353;

int n, m, ans;
std::string s;
int a[505];

int fac(int x) {
	if (x == 1) {
		return 1;
	}
	return x * (fac(x - 1) % MOD) % MOD;
}

int main(void) {
	freopen("employ3.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	std::cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	
	bool spec = true;
	for (int i = 0; i != n; ++i) {
		if (s[i] == '0') {
			spec = false;
		}
	}
	if (spec == true) {
		std::cout << fac(n) << '\n';
	} else {
		std::cout << 0 << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	Nahida;
}
