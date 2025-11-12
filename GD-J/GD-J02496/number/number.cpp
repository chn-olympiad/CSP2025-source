#include <bits/stdc++.h>
using namespace std;
char nums[10000005];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length(), cnt = 0;
	for(int i=0;i<len;i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			nums[cnt] = s[i];
			cnt++;
		}
	}
	sort(nums,nums+cnt);
	if(nums[cnt-1] == '0') {
		cout << 0;
		return 0;
	}
	for(int i=cnt-1;i>=0;i--) {
		cout << nums[i];
	}
	return 0;
}
