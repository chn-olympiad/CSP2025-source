#include <bits/stdc++.h>
using namespace std;
int a[1010], n, m, my, rk, x, y;
void solve(){
	cin >> n >> m;
	for (int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	my = a[1];
	sort(a + 1, a + n*m + 1);
	rk = n*m - (lower_bound(a + 1, a + n*m + 1, my) - a) + 1;
//	cout << my << " " << rk << "\n";
	if (rk % n == 0){
		x = rk / n;
		y = (x % 2 ? n : 1);
	} else {
		x = rk / n + 1;
		y = rk % n;
	}
	cout << x << " " << y;
} 

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
}
