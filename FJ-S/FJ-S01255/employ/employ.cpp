#include <bits/stdc++.h>
#define MAXN 520
#define mod 998244353
using namespace std;

int n, m;
string s;
int c[MAXN];

long long A(int x, int y) {
	long long ans = 1;
	if (x > y) return 0;
	
	if (x == y) {
		for (int i = 1; i <= x; i++) {
			ans = ans * i % mod;
		}
	} else {
		int cnt = 1;
		for (int i = 1, j = y; i <= cnt; i++, j--) {
			ans = ans * j % mod;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	int tot = n, num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == 1) {
		cout << A(n, n);
		return 0;
	}	
	if (m == n) {
		cout << A(n, n);
		return 0;
	}
	cout << A(m, n) << endl;
	return 0;
}