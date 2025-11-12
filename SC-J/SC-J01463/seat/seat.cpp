#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 15 * 15;
int n, m, s, p = 1;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 2; i <= n * m; i++) {
		int a;
		cin >> a;
		if(a > s) p++;
	}
	int h = 0, l = 0;
	l = (p + n - 1) / n;
	if(l % 2 == 1) {
		h = (p - 1) % n + 1;
	}
	else {
		h = n * l - p + 1;
	}
	cout << l << ' ' << h << endl;
	return 0;
}