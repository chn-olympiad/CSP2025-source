#include <bits/stdc++.h>
using namespace std;

int n, m, k, l, r, a[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	k = a[1], sort(a + 1, a + n * m + 1), k = lower_bound(a + 1, a + n * m + 1, k) - a, k = n * m - k + 1;
	l = (k + n - 1) / n;
	if(l & 1) r = (k - (l - 1) * n);
	else r = n - (k - (l - 1) * n) + 1;
	cout << l << " " << r << "\n";
	return 0;
} 
