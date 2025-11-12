#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
int a[510];
int sf(string s) {
	long long ans = 0;
	int L = s.size();
	for (int i = 0; i < L;i++) {
		ans = (ans * 2 + int(s[i] -'0')) % mod;
	}
	return ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	long long x = sf(s);
	cout << x << endl;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!a[i]) continue;
		x *= a[i];
		x %= mod;
		cout << x << " ";
	}
	cout << endl;
	cout << x / 6 << endl;
	return 0;
}

