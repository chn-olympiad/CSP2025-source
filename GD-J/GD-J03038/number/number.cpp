#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> nums;
	for(char i : s) if(i >= '0' && i <= '9') nums.push_back(i - '0');
	sort(nums.begin(), nums.end(), [&] (const int& x, const int& y) {
		return x > y;	
	});
	for(int i : nums) cout << i;
	return 0;
}
