#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool c(int n, int m) {
	if(n > m) {
		return 1;
	}
	return 0;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int l = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[l++] = s[i] - '0';
		}
	}
	sort(a, a+l, c);
	bool f = 0;
	for(int i = 0; i < l; i++) {
		if(a[i] != 0) {
			f = 1;
		}
		if(f) {
			cout << a[i];
		}
	}
	return 0;
}
