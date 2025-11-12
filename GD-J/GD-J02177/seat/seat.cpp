#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int a[110];

bool cmp(int ax, int ay) {
	return ax > ay;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	memset(a, 0, sizeof(a));
	int n, m, targ = 0;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) {
		cin >> a[i];
		if(i == 1) targ = a[i];
	}
	sort(a+1, a+1+n*m, cmp);
//	cout << targ << endl;
	for(int i=1; i<=n*m; i++) {
		if(a[i] == targ) {
//			cout << i << endl;
			if(((i-1) / n) % 2) {
//				cout << 1 << endl;
				cout << (i-1) / n + 1 << ' ';
				if(i % n == 1) cout << n;
				else cout << (n - (i%n) + 1) % n;
			} else {
				if(i % n == 0) {
//					cout << 2 << endl;
					cout << i / n << ' ' << n;
				}
				else {
//					cout << 3 << endl;
					cout << i / n + 1 << ' ';
					if(i%n == 0) cout << n;
					else cout << i % n;
				}
			}
		}
	}
	return 0;
}
