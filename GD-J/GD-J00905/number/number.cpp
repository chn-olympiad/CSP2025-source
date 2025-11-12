#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int x, int y) { return x > y; }

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s; cin >> s;
	vector<int> nums;
	for(int i = 0;i < s.size();i++) {
		if('0' <= s[i] && s[i] <= '9') nums.push_back(s[i] - '0');
	} sort(nums.begin(), nums.end(), cmp);
	for(int i = 0;i < nums.size();i++) cout << nums[i];
	return 0;
}
