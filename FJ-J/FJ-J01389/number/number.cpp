#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	
	vector<int> num;
	for (auto i : s) {
		if (i >= '0' && i <= '9') {
			num.push_back(i - '0');
		}
	}
	
	sort(num.begin(), num.end(), greater<int>());
	
	if (num[0] == '0') {
		puts("0");
		return 0;
	}
	
	for (auto i : num) {
		printf("%d", i);
	}
	puts("");
	
	return 0;
}