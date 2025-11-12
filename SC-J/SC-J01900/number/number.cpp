#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long> ans;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') ans.push_back(s[i] - '0');
	}
	sort(ans.begin(), ans.end(),greater<long long>());
	for (auto c : ans) cout << c;
	return 0;
}