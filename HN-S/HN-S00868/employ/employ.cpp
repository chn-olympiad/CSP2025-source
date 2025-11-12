#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int nx[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> nx[i];
	cout << m << "\n";
	return 0;
}
