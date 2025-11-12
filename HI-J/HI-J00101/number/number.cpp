#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> s1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') s1.push_back(s[i] - '0');
	long long n = s1.size();
	sort(s1.begin(), s1.end());
	for (int i = n - 1; i >= 0; i--) cout << s1[i];
	return 0;
} 
