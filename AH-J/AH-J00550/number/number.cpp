#include <bits/stdc++.h>
using namespace std;
bool cmp (int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector<int> nums;
	int len = s.length();
	for (int i = 0; i < len; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			nums.push_back(s[i] - '0');
		}
	}
	sort(nums.begin(), nums.end(), cmp);
	int sz = nums.size();
	for (int i = 0; i < sz; i ++) {
		cout << nums[i];
	}
	return 0;
}
