#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, cnt = 1, a[100005];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++) {
		cin >> a[i];
		if(a[i] > a[1]) cnt ++; 
	}
	int lie, hang, c = 0;
	for(int i = 1;i <= m;i ++) {
		if(i % 2) {
			for(int j = 1;j <= n;j ++) {
				c ++;
				if(c == cnt) {
					lie = i; hang = j;
					cout << lie << " " << hang << "\n";
					return 0;
				}
			}
		}else {
			for(int j = n;j >= 1;j --) {
				c ++;
				if(c == cnt) {
					lie = i; hang = j;
					cout << lie << " " << hang << "\n";
					return 0;
				}
			}
		}
	}
	cout << lie << " " << hang << "\n";
	return 0;
}
