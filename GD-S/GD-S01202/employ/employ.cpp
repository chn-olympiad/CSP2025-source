#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	cout << n * (n - 1);

	return 0;
}

