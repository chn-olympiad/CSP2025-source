//100pts
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	char c;
//	while (cin >> c) {
//		if (c >= '0' && c <= '9') {
//			v.push_back(c - '0');
//		}
//	}
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}
//rp++