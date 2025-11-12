#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool cmp(int a, int b) {
	return a > b; 
}
int m, n, score, pos;
int a[400];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
		if (i == 1) score = a[i];
	}
	sort(a + 1, a + m * n + 1, cmp);
	for (int i = 1; i <= m * n; i++) {
		if (a[i] == score) {
			pos = i;
			break;
		}
	}
	int t = pos % n, tu = pos / n;
	if (t == 0) {
		if (tu % 2 == 0) {
			cout << tu << " " << "1";
		} else {
			cout << tu << " " << n;
		}
	} else {
		if (tu % 2 == 0) {
			cout << tu + 1 << " " << t;
		} else {
			cout << tu + 1 << " " << n - t + 1;
		}
	}

	
	
	
	
	
	return 0;
}
