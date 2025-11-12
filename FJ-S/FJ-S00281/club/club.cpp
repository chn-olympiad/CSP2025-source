#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

struct node {
	int x = 0, y = 0, z = 0;
	int _first = 0, _second = 0;
};

bool cmp(node _l, node _r) {
	return (_l._first - _l._second) < (_r._first - _r._second);
}

void solve() { 
	int n = read(), ans = 0;
	vector <node> a(n + 10);
	vector <node> _x, _y, _z;
	for(int i = 1;i <= n;i++) {
		a[i].x = read(), a[i].y = read(), a[i].z = read();
//		cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
		if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
			ans += a[i].x;
			a[i]._first = a[i].x;
			if(a[i].y >= a[i].z) a[i]._second = a[i].y;
			else a[i]._second = a[i].z;
			_x.push_back(a[i]);
		} else {
			if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
				ans += a[i].y;
				a[i]._first = a[i].y;
				if(a[i].x >= a[i].z) a[i]._second = a[i].x;
				else a[i]._second = a[i].z;
				_y.push_back(a[i]);
			} else {
				ans += a[i].z;
				a[i]._first = a[i].z;
				if(a[i].x >= a[i].y) a[i]._second = a[i].x;
				else a[i]._second = a[i].y;
				_z.push_back(a[i]);
			}
		}
	}
//	cout << ((int)_x.size()) << " " << ((int)_y.size()) << " " << ((int)_z.size()) << " " << n / 2 << "\n";
	if(((int)_x.size()) > (n / 2)) {
		sort(_x.begin(), _x.end(), cmp);
		for(int i = 0;i < ((int)_x.size()) - n / 2;i++) {
//			cout << _x[i]._first << " " << _x[i]._second << "\n"; 
			ans -= (_x[i]._first - _x[i]._second);
//			cout << i << " " << (_x[i]._first - _x[i]._second) << " " << ans << "\n";
		}
	} else {
		if(((int)_y.size()) > (n / 2)) {
			sort(_y.begin(), _y.end(), cmp);
			for(int i = 0;i < ((int)_y.size()) - n / 2;i++) {
//				cout << _y[i]._first << " " << _y[i]._second << "\n"; 
				ans -= (_y[i]._first - _y[i]._second);
//				cout << i << " " << (_y[i]._first - _y[i]._second) << " " << ans << "\n";
			}
		} else {
			if(((int)_z.size()) > (n / 2)) {
				sort(_z.begin(), _z.end(), cmp);
				for(int i = 0;i < ((int)_z.size()) - n / 2;i++) {
//					cout << _z[i]._first << " " << _z[i]._second << "\n"; 
					ans -= (_z[i]._first - _z[i]._second);
//					cout << i << " " << (_z[i]._first - _z[i]._second) << " " << ans << "\n";
				}
			}
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

