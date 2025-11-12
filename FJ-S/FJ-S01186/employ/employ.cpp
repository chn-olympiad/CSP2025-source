#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
int a[N], f[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + bool(s[i - 1] == '0');
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	return 0; 
}
