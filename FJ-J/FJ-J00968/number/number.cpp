#include <bits/stdc++.h>

std::string s, ans;
int cnt[10] = {0};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::cin >> s;
	for(char c: s) {
		cnt[c - '0'] += 1;
	}
	for(int i = 9; i >= 0; --i) {
		for(int j = 0; j < cnt[i]; ++j) 
			ans += char(i + '0');
	}
	if(ans[0] == '0') ans = "0";
	std::cout << ans;
	
	return 0;
}
