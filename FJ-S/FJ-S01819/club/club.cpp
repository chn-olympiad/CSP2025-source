#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, ans;
int num[5];

struct node {
	int a, b, c;
}a[N];

bool cmd(node x, node y) {
	return x.a + y.b > y.a + x.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while ( t-- ) {
		num[1] = num[2] = num[3] = 0;
		ans = 0;
		cin >> n;
		for ( int i = 1; i <= n; i++ ) {
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		sort(a + 1, a + n + 1, cmd);
		for ( int i = 1; i <= n; i++ ) {
			if ( num[1] < n / 2 ) {
				num[1]++;
				ans += a[i].a;
			} else {
				if ( a[i].b > a[i].c ) {
					if ( num[2] < n / 2 ) {
						num[2]++;
						ans += a[i].b;
					} else {
						num[3]++;
						ans += a[i].c;
					}
				} else {
					if ( num[3] < n / 2 ) {
						num[3]++;
						ans += a[i].c;
					} else {
						num[2]++;
						ans += a[i].b;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
