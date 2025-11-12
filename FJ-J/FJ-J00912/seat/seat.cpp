#include<bits/stdc++.h>
using namespace std;
int a[105],r;
int cmp(int &a, int &b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	r = a[1];
	for(int i = 2; i <= n * m; i ++)
		cin >> a[i];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n * m; i ++) {
		if(a[i] == r) {
			int column = i/n;
			if(i%n) column ++;
			if(!(column%2))
				cout << column << ' ' << n-i%n+1;
			else
				cout << column << ' ' << (i%n == 0 ? n : i%n);
			break;
		}
	}
}
