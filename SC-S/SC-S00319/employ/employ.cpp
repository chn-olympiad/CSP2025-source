#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

const int N = 1E6 + 10;
char a[N];
const int MOD = 998244353;

int A(int n) {
	int ret = 1;
	for (int i = n; i >= 1; --i) {
		ret = (ret % MOD) * ((n-1) % MOD) % MOD;
	}
	return ret;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	bool flag = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		flag = flag && (a[i] == '0' ? true : false);
	}
	
	if (flag == true) {
		cout << A(n) << endl;
	}
	
	return 0;
}
