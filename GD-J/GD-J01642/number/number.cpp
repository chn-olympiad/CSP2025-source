#include<bits/stdc++.h>
using namespace std;
vector<int> n;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n.push_back((int)(s[i] - '0'));
		}
	}
	
	sort(n.begin(), n.end(), greater<int>());
	
	for (int i = 0; i < n.size(); i++) {
		cout << n[i];
	}
	
	return 0;
}
