#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;
int a[N];

bool cmp (int &a, int &b) {
	return a > b;
}

signed main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int num = a[1];
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num) {
			if (i > n) {
				//cout << i << '\n';
				double t = n * 1.0;
				int x = ceil(i / t);
				cout << x << " ";
				int y = i % n;
				//cout << y << '\n';
				if (x % 2 == 0) {
					cout << n - (i - n * (x - 1)) + 1;
				}
				else cout << y;
			}
			else cout << 1 << " " << i;
			return 0;
		}
	}
	return 0;
}
