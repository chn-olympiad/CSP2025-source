#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str, nums = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			nums.push_back(str[i]);
		}
	}
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	if (nums[0] == '0') {
		cout << 0;
	} else {
		cout << nums;
	}
	return 0;
}
