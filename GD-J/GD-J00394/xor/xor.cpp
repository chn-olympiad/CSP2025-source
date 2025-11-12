#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int qwe = 5e5 + 10;
ll k, n, a[qwe], ans, cnt;

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	//cout << k << " ";
	for ( int i = 1; i <= n; i ++ ) cin >> a[i];
	for ( int i = 1; i <= n ; i ++ ) {
		ans = ans ^ a[i];
		if ( ans == k ) {
			ans = 0;
			cnt ++;
			//cout << i << " ";
		}
		else if ( a[i] == k ) {
			ans = 0;
			cnt ++;
			//cout << i << " ";
		}
		//cout << ans << " ";
	}
	cout << cnt;
	return 0;
}
