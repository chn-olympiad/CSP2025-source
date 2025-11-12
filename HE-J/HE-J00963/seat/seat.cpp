#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
bool more(int a, int b) {return a>b;}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, p;
	int a[100];
	cin >> n >> m;
	for (int i = 0; i < n*m; i++) cin >> a[i];
	k = a[0];
	sort(a, a+n*m, more);
	for (int i = 0; i < n*m; i++) {
		if (a[i] == k) {
			p = i;
			break;
		}
	}
	
	cout << p/n+1 << ' ';
	if (p%(2*n)>=n) cout << n-p%n;
	else cout << p%n+1;
	return 0;
}
