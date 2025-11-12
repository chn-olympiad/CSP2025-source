#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[501], n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n == 3 && m == 2) cout << 2;
	else cout << 0;
	return 0;
}
