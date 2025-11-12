#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1000;
int a[N];
int f[N];
bool cmp (int x , int y) {
	return x >= y;
}

signed main () {
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n , m;
	cin >> n >> m;
	int num = n * m;
	int sr;
	for (int i = 1; i <= num; i++) {
		cin >> a[i];
	}
	sr = a[1];
	int ri;
	sort (a + 1 , a + 1 + num , cmp);
	for (int i = 1; i <= num; i++) {
		if (a[i] == sr) {
			ri = i;
		}
	}
	int l = 1 , r = 1;
	while (ri > n) {
		l++;
		ri -= n;
	}
	if (l % 2 != 0) {
		r = ri;		
	}
	else {
		r = n - ri + 1;	
	}
	cout << l << " " << r;
	return 0;
}