#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y) {
	return x > y;
}
int n,m;
int a[105];
int x;
int p;
int ax = 0,ay = 0;

int main () {
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m; ++i) {
		cin >> a[i];
		x = a[1];
	}
	sort (a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m; ++i) {
		p = i;
		if (a[p] == x) {
			break;
		}
	}
	ax = (p + n - 1) / n;
	if (ax % 2 == 0) {
		ay = n + 1 - p % n;
	} else {
		ay = p - (ax - 1) * n;
	}
	cout << ax << " " << ay;
	fclose (stdin);
	fclose (stdout);
	return 0;
}

