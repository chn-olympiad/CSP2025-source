#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans;
	vector<int> cnt(10, 0);
	cin >> s;
	sort(s.begin(), s.end());
	for (int i = s.size() - 1; i >= 0; i--) 
		if ('0' <= s[i] && '9' >= s[i]) 
			cout << s[i];
} 
