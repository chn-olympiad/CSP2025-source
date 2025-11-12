#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[12];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	ll len = s.size();
	for (ll i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i]-'0']++;
		}
	}
	
	int ch = 0;
	for (ll i = 9; i >= 0; i--) {
		if (ch == 0 && i == 0) {
			cout << 0;
			return 0;
		}
		if (a[i] > 0) ch++;
		for (ll j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
} 