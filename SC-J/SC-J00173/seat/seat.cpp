#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int scr[225];
	for (int i = 1; i <= n*m; i ++) {
		cin >> scr[i];
	}
	int fst = scr[1];
	int d=0, r=0;
	sort(scr, scr+n*m+1, cmp);
	for (int i = 1; i <= n*m; i ++) {
		if (scr[i] == fst) {
			d = i/n;
			r = i%n;
			if (r) d++;
		}
	}
	if (!r) r = n;
	if (d % 2 == 0) r = n-r+1;
	cout << d << " ";
	cout << r << "\n"; 
	return 0;
} 