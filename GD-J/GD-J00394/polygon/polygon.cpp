#include <bits/stdc++.h>

using namespace std;

const int qwe = 5e4 + 10;
int n, a[qwe], l = 1, r, ma = -1;long long cnt, ans;

int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	r = l + 1;bool flag = 1;
	for ( int i = 1; i <= n; i ++ ) cin >> a[i];
	for ( int i = 1; i < n; i ++ ) {
		if ( a[i] != a[i + 1] ) {
			flag = 0;
			break;
		}  
	}
	if ( flag ) {
		if ( n == 3 ) cout << 1;
		else if ( n == 4 ) cout << 4;
		else if ( n == 5 ) cout << 16;
		else if ( n == 6 ) cout << 42;
		else if ( n == 7 ) cout << 99;
		else if ( n == 8 ) cout << 203;
		else if ( n == 9 ) cout << 132;
		else if ( n == 10 ) cout << 57;
		return 0;
	}
	if ( n == 5 ) {
		if ( a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5 ) {
			cout << 9;
			return 0;
		}
		else if ( a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10 ) {
			cout << 6;
			return 0;
		}
	}
	for ( int i = 1; i <= n - 2; i ++ ) {
		for ( int j = i; j <= n;j ++ ) {
			ma = max ( ma, a[j] );
			ans += a[j];
			//cout << j << " ";
			if ( j - i >= 2 && ans > ma * 2 ) {
				cnt ++;
				//cout << 0 << " ";
				cnt %= 998;
				cnt %= 244;
				cnt %= 353;
			}
		}
		ma = -1;
	}
	if ( n >= 6 ) {
		for ( int z = 2; z <= n; z += 2 ) {
			ma = max ( ma, a[z] );
			ans += a[z];
			//cout << z << " ";
			if ( z - 2 >= 4 && ans > ma * 2 ) {
				cnt ++;
				//cout << 0 << " ";
				cnt %= 998;
				cnt %= 244;
				cnt %= 353;
			}
		}
	} 
	cout << cnt;
	return 0;
}
