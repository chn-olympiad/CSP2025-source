#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int MOD = 998244353;
int n, m, c[505];
string s;
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		ans = ans * i % MOD;
	}
	cout << ans % MOD;
	return 0;
}
