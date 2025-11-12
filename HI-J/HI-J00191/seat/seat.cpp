#include<bits/stdc++.h>
using namespace std;

int a[10005];
int n, m;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m; // n–– m¡– 
	
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int r = a[1];
	
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	 
	int p;
	for (int i = 1; i <= n * m; i ++) {
		if (r == a[i]) {
			p = i;
			break;
		}
	}
	
	int mm = p / n;
	if (p % n) {
		cout << ++ mm << " ";
		if (mm % 2) {
			cout << p % n << endl;
		} else {
			cout << n - p % n + 1 << endl;
		}
	} else {
		cout << mm << " ";
		if (mm % 2) {
			cout << n << endl;
		} else {
			cout << 1 << endl;
		}
	}
	
	return 0;
}


