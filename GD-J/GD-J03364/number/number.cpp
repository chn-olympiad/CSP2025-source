#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
vector<int> num;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++) {
		if('0' <= s[i] && s[i] <= '9') {
			num.push_back(s[i] - '0');
		}
	}
	sort(num.begin(), num.end(), greater<int>() );
	int ans = num.size();
	for(int i = 0;i < ans;i++) {
		cout << num[i];
	}
	cout << "\n";
	return 0;
}
