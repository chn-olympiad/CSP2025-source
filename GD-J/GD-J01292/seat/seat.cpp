#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, y, l, r;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	x = a[1];
	sort(a + 1, a + n * m + 1); reverse(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++) if (a[i] == x){y = i; break;}
	l = ceil(double(y)/ n);
	cout << l << " ";
	if (l % 2) cout << y - (l - 1) * n;
	else cout << n - (y - (l - 1)* n);
	return 0;
} 
