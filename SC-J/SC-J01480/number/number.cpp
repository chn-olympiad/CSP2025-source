#include <bits/stdc++.h>
using namespace std;

string s;
int nums[20];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = (int)s.length();
	for (int i = 0;i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9') nums [s[i] - '0']++;
	} for (int i = 9;i >= 0; --i) {
		while (nums[i] > 0) {
			cout << i;
			nums[i]--;
		}
	} return 0;
} 