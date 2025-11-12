#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6 + 7;
ll n;
ll ln;
ll a[N];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	
	n = s.size();
	
	for (ll i = 0; i < n; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++ln] = s[i] - '0';
		}
	}
	
	sort(a + 1, a + ln + 1);
	
	for (int i = ln; i >= 1; --i) {
		cout << a[i];
	}
	
	return 0;
}