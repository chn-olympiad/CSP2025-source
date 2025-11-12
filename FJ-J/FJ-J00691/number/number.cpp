#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> a;
	int b[MAXN];
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a.push_back(s[i] - '0');
		}
	}
	for (int i = 0;i < a.size();i++) {
		b[i] = a[i];
	}
	sort(b,b + a.size(),greater<int>());
	if (b[0] == 0) {
		cout << 0;
		return 0;
	} 
	for (int i = 0;i < a.size();i++) {
		cout << b[i];
	}
	return 0;
} 
