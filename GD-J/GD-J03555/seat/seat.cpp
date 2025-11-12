#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 50;

int n, m, i = 1, j = 1, a[N], number = 0, t;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int k = 1; k <= n * m; ++ k) {
		cin >> a[k];
	}
	
	number = a[1];
	
	sort(a + 1, a + 1 + n * m, cmp) ;
	
	for(int k = 1; k <= n * m; ++ k) {
		if(a[k] == number) {
			t = k;
			break;
		}
	}
	
	number = 0;
	
	while(i <= n && j <= m) {
		number ++;
		
		if(number == t) {
			cout << j << " " << i << "\n";
			return 0;
		}
		
		if(j % 2) {
			if(i == n) {
				j ++;
			} else {
				i ++;
			}
		} else {
			if(i == 1) {
				j ++;
			} else {
				i --;
			}
		} 
	}
	
	cout << j << " " << i << "\n";
	return 0;
}
