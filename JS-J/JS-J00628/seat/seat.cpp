#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[110], k, p;
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> k;
	a[1] = k;
	for (int i=2; i<=n*m; i++)
		cin >> a[i];
	sort(a+1, a+n*m+1);
	for (int i=1; i<=n*m; i++)
		if (a[i] == k)
			p = n * m - i + 1;
	for (int i=1; i<=m; i++){
		if (p > n)
			p -= n;
		else{
			cout << i << ' ' << (i % 2 ? p : n - p + 1) << '\n';
			return 0;
		}
	}
}