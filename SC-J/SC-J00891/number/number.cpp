#include <bits/stdc++.h>

bool flag = false;
std::string s, ans = "";

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			ans += s[i];
		}
	}
	std::sort(ans.begin(), ans.end(), std::greater <char> ());
	if (ans[0] == '0') {
		std::cout << '0';
	} else {
		std::cout << ans;
	}
	return 0;
} 