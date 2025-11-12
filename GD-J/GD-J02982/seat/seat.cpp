#include <bits/stdc++.h>

using namespace std;

struct __ {
	int val, po;
}a[1145];
int n, m;
bool cmp(__ a, __ b) {
	return a.val > b.val;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i].val;
		a[i].po = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int ans = 1;
	for(ans = 1; ans <= n * m; ans++) {
		if(a[ans].po == 1) break;
	}
	
	if(((ans + n - 1) / n) % 2 == 1) {
		cout << (ans + n - 1) / n << " " << (ans - 1) % n + 1;
	}
	else {
		cout << (ans + n - 1) / n << " " << n - ((ans - 1) % n + 1) + 1;
	}
	
	return 0;
} 

