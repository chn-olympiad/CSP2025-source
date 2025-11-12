#include <bits/stdc++.h>
using namespace std;

int num[10];

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	std::ios::sync_with_stdio (false);
	std::cin.tie (nullptr);
	std::cout.tie (nullptr);
	
	string s, res;
	std::cin >> s;
	size_t len = s.size ();
	
	for (size_t i = 0; i < len ;i ++) {
		if (isdigit (s[i]) ) {
			num[s[i] - '0'] ++;
		}
	}
	
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= num[i]; j ++) {
			res = res + (char) (i + '0');
		}
	}
	
	std::cout << res << "\n";
	return 0;
}
