#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
	}
	cout << '\n';
	return 0;
}
