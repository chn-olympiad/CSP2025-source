#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	vector<char> nums;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] >= 48 && s[i] <= 57) {
			nums.push_back(s[i]);
		}
	}
	sort(nums.rbegin(), nums.rend());
	string ans = "";
	for(int i = 0; i < nums.size(); ++i) {
		ans += nums[i];
	}
	cout << ans;
	return 0;
}
