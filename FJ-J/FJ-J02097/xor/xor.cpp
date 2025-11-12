#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, k, a, m, ans;
int sum[N];

struct node {
	int l, r, s;
}s[N];

bool cmd(node x, node y) {
	return x.s > y.s;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a;
		sum[i] = ( sum[i - 1] xor a );
	}
	for ( int l = 1; l <= n; l++ ) {
		for ( int i = 1; i + l - 1 <= n; i++ ) {
			int j = i + l - 1;
			if ( ( sum[j] xor sum[i - 1] ) == k ) {
				s[++m] = {i, j, j - i + 1};
			}
		}
	}
	sort(s + 1, s + m + 1, cmd);
	ans = m;
	for ( int i = 1; i <= m; i++ ) {
		for ( int j = i + 1; j <= m; j++ ) {
			int l1 = s[i].l, l2 = s[j].l, r1 = s[i].r, r2 = s[j].r;
			if ( l1 <= r2 && r1 >= r2 || l1 <= l2 && r1 >= l2 ) {
				ans--;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
