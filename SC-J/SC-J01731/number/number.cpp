#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	string s;
	cin >> s;
	vector<int> ans;
	for (auto c : s) {
		if (c >= '0' && c <= '9') {
			ans.push_back(c - '0');
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for (auto x : ans) {
		cout << x;
	}
	cout << "\n";
	return 0;
}