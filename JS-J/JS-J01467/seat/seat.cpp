#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, m, a[110];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	int sco = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int pos;
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == sco) {
			pos = i;
			break ;
		}
	}
	int x = pos / (n * 2);
	int y = pos % (n * 2);
	if(y <= n)
		cout << x * 2 + 1 << ' ' << y << '\n';
	else
		cout << x * 2 + 2 << ' ' << n - (y - n) + 1 << '\n';
	return 0;
}