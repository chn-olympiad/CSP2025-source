#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;
int a[maxn];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, cnt = 0;
	cin >> n >> m >> a[1];
	t = a[1];
	for(int i=2; i<=n*m; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n*m+1);
	for(int i=n*m; i>=1; i--) {
		++cnt;
		if(a[i] == t) {
			break;
		}
	}
	int lie = cnt / n + (cnt%n != 0);
	int hang = cnt % n;
	if(hang == 0) hang = n;
	if(lie % 2 == 1) {
		cout << lie << " " << hang;
	} else {
		cout << lie << " " << n-hang+1;
	}
	return 0;
}
