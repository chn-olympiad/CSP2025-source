#include <bits/stdc++.h>
using namespace std;
int n , m , a[110] , maxx , id;
signed main () {
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++) {
		cin >> a[i];
		if (a[i] > a[1]) maxx ++;
	}
	id = maxx + 1;
	for (int i = 1;i <= m;i ++) {
		if (id <= n) {
			cout << i << ' ';
			if (i & 1) cout << id;
			else cout << n - id + 1;
			break;
		}
		else id -= n;
	}
	
	return 0;
} 
