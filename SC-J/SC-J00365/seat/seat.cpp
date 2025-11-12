#include<bits/stdc++.h>
using namespace std;
int fx(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[110];
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + n * m + 1, fx);
	int x = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(i % 2 == 1) {
				if(a[++x] == r) {
					cout << i << ' ' << j;
					return 0;
				}
			}
			else {
				if(a[++x] == r) {
					cout << i << ' ' << n - j + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}