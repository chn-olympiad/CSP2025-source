#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	bool _f;
	int _x = 0, _y = 0;
	int _a;
};
bool cmp(node x,node y) {
	return x._a > y._a;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <node> a(n * m + 10);
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i]._a;
		if(i == 1) a[i]._f = 1;
//		cout << a[i]._f << " ";
	}
//	cout << "\n";
//	cout << a[1]._f << "\n";
	sort(a.begin() + 1, a.begin() + n * m + 1, cmp);
	for(int i = 1;i <= m;i++) {
		if(i & 1) {
			for(int j = 1;j <= n;j++) {
				a[(i - 1) * n + j]._x = i;
				a[(i - 1) * n + j]._y = j;
//				cout << a[i * n - n + j]._a << " " << i << " " << j << "\n";
			}
		} else {
			for(int j = 1;j <= n;j++) {
				a[i * n - j + 1]._x = i;
				a[i * n - j + 1]._y = j;
//				cout << a[i * n - j + 1]._a << " " << i << " " << j << "\n";
			}
		}
//		cout << "\n";
	}
	for(int i = 1;i <= n * m;i++) {
//		cout << a[i]._a << "\n";
		if(a[i]._f == 1) return cout << a[i]._x << " " << a[i]._y << "\n",0;
	}
//	return 0;
}

