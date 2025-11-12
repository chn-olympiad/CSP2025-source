#include <bits/stdc++.h>
using namespace std;

int n, m;
int pos = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int se;
	cin >> se;
	for (int i = 1; i < n * m; i ++) {
		int s;
		cin >> s;
		if (s > se) pos ++;
	}
	int w = pos / n;
	int v = pos % n;
	int np = w, mp;
	if (v > 0) {
		np ++;
		if (np % 2 == 0) {
			mp = m - v + 1;
		} else {
			mp = v;
		}
	} else {
		if (np % 2 == 0) {
			mp = 1;
		} else {
			mp = n;
		}
	}
	
	cout << np << " " << mp;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
