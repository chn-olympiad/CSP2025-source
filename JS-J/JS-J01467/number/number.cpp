#include <bits/stdc++.h>
#define int long long

using namespace std;
string s;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	vector<int> nums;
	for(const auto &c : s) {
		if(isdigit(c)) 
			nums.emplace_back(c - '0');
	}
	sort(nums.begin(), nums.end(), greater<int>());
	bool flag = false;
	for(const auto &p : nums) {
		if(p != 0) 
			flag = true;
	}
	if(!flag) {
		cout << 0 << '\n';
		return 0;
	}
	for(const auto &p : nums) 
		cout << p;
	cout << '\n';
	return 0;
}