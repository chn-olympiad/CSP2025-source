#include <iostream>
#include <string>

const int MOD = 998244353;

int n, a[5005], ans;

std::string last(int m) {
	std::string ans = "";
	for (int i = n; i != n - m; --i) {
		ans = char(i + '0') + ans;
	}
	return ans;
}
std::string next(std::string cb, int m) {
	std::string ans = cb;
	int pos = m;
	for (int i = m - 1; i >= 0; --i) {
		if (cb[i] != n - m + 1 + i + '0') {
			ans[i] = cb[i] + 1;
			for (int j = i + 1; j <= m - 1; ++j) {
				ans[j] = ans[j - 1] + 1;
			}
			break;
		}
	}
	return ans;
}

bool polygon(std::string s) {
	int max = -1, sum = 0;
	for (int i = 0; i != s.size(); ++i) {
		max = std::max(max, a[s[i] - '0']);
		sum += a[s[i] - '0'];
	}
	return sum > (max * 2);
}

int main(void) {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	
	std::string cb = "";
	for (int m = 3; m < n; ++m) {
		for (int i = 1; i <= m; ++i) {
			cb = cb + char(i + '0');
		}
		
		while (true) {
			if (polygon(cb)) {
				ans = (ans + 1) % MOD;
			}
			if (cb == last(m)) {
				break;
			}
			cb = next(cb, m);
		}
		
		cb = "";
	}
	
	for (int i = 1; i <= n; ++i) {
		cb = cb + char(i + '0');
	}
	if (polygon(cb)) {
		++ans;
	}
	
	std::cout << ans << '\n';
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
