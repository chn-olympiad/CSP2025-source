#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll b = 0;
ll a[1000100] = {0};

bool cmp (ll x, ll y) {
	return x > y;
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[b] = s[i] - 48;
			b += 1;
		}
	}
	sort(a, a + b, cmp);
	for (ll i = 0; i < b; i++) {
		cout << a[i];
	}
	cout << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
