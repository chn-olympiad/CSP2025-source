#include <bits/stdc++.h>
using namespace std;

int n, m, nm, pos;
int a[105];

void bubble () {
	for (int i=1; i<nm; i++) {
		for (int j=nm; j>=i+1; j--) {
			if (a[j] > a[j-1]) swap(a[j], a[j-1]);
		}
	}
}

void snake (int x, int y) {
	int sx=0, sy=1, s=0;
	for (int i=1; i<=x; i++) {
		for (int j=1; j<=y; j++) {
			s++;
			if (j==1) sx++;
			else if (i%2==0) sy--;
			else sy++;
			if (s==pos) break;
		}
	}
	
	cout << sx << ' ' << sy;
}

int main() {
	freopen("seat3.in", "r", stdin);
	freopen("seat3.out", "w", stdout);
	
	cin >> n >> m;
	nm = n*m;
	for (int i=1; i<=nm; i++) cin >> a[i];
	int r = a[1];
	bubble ();
	for (int i=1; i<=nm; i++) {
		if (a[i] == r) {
			pos = i;
		}
	}
	snake(m, n);
	return 0;
}
