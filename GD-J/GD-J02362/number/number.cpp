#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	priority_queue <int> digit;
	for (auto &i : a) {
		if (isdigit(i)) digit.push(i - '0');
	}
	while (digit.size()) {
		cout << digit.top();
		digit.pop();
	}
	return 0;
}
