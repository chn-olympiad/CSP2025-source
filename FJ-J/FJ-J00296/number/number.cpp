#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);//#Shang4Shan3Ruo6Shui4
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			s[cnt++] = s[i];	
		}
	}
	
	vector<int> nums(cnt);
	
	for (int i = 0; i < cnt; i++) {
		nums[i] = s[i] - '0';
	}
	
	sort(nums.begin(), nums.end(), greater<int>());
	
	for (int i = 0; i < cnt; i++) {
		cout << nums[i];
	}

	return 0;
}

