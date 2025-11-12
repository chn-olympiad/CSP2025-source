#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

bool cmp(int a, int b) {
	return a > b;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	char c;
	vector<int> nums;
	while(cin >> c) {
		if('0' <= c && c <= '9') { //c is a number
			nums.push_back((c-'0'));
		} 
	}
	sort(nums.begin(), nums.end(), cmp);
	
	if(nums[0] == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	cout << "\n";
	return 0;
}
