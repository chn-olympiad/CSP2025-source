#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, m, a[maxn], now;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++) cin >> a[i];
	int x = a[1], d, y = 1;
	sort(a + 1, a + n*m + 1, cmp);
	for(int i = 1; i <= n*m; i ++) {
		if(a[i] == x) {
			d = i;
			break;
		}
	}
	for(int i = 1; i <= m; i ++) {
		if(i % 2) {
			now ++;
			while(1) {
				if(now == d) {
					cout << i << " " << y;
					return 0;
				}
				if(y == n) break;
				y ++;
				now ++;
				//cout << i << " " << y << "\n";
			}
		}
		else {
			now ++;
			while(1) {
				if(now == d) {
					cout << i << " " << y;
					return 0;
				}
				if(y == 1) break;
				y --;
				now ++;
				//cout << i << " " << y << "\n";
			}
		}
	}
	return 0;
}
