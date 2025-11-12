#include<bits/stdc++.h>
using namespace std;
int a[105] = { };
bool cmp(int x, int y) {
	return x > y; 
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);	
	int n, m, c, r;
	cin >> n >> m;
	int a[n * m + 5];
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if(a[i] == k) k = i; 
	if (k % n == 0) {
		if ((k / n) % 2) {
			cout << k / n << " " << n;
			return 0;
		} else {
			cout <<  k / n << " " << 1;
			return 0; 
		}
	} else {
		c = k / n + 1;
		if (c % 2) r = k % n;
		else r = n - k % n + 1; 
	} cout << c <<" "<< r;
	return 0;
}
