#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	k = a[1];
	sort(a+1, a+1+n*m, cmp);
	int idx = 0;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==k) {
			idx = i;
			break;
		}
	}
	int y = (idx+n-1)/n;
	int tmp = (y-1)*m;
	idx -= tmp;
	cout << y << ' ';
	if(y%2==0) {
		cout << n-(n-idx)-1;
	} else {
		cout << idx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
