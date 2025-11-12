#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
typedef long long ll;
ll a[N], ans = 0;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[ans] = s[i] - 48;
			ans++;
		}
	}
	sort(a, a + ans);
	for (ll i = ans - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
