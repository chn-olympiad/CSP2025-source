#include<bits/stdc++.h>
using namespace std;

int n, m, r, num;
int a[200];

bool cmd(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n * m; i++ ) {
		cin >> a[i];
		r = a[1];
	}
	sort(a + 1, a + n * m + 1, cmd);
	for ( int i = 1; i <= n * m; i++ ) {
		if ( a[i] == r ) {
			num = i;
			break;
		}
	}
	int ans1 = num / n + ( num % n ? 1 : 0 );
	int ans2 = num % n;
	ans2 = ( ans2 ? ans2 : n );
	cout << ans1;
	cout << " " << ( ans1 % 2 ? ans2 : n - ans2 + 1 );
	return 0;
}
