#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], R;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i){
		cin >> a[i];
	}
	R = a[1];
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; ++i){
		if (R == a[i]){
			R = i;
			break;
		}
	}
	R = n * m - R + 1;
	int c, r;
	if (R % n == 0){
		c = R / n;
		if (c % 2 == 1){
			r = n;
		}
		else{
			r = 1;
		}
	}
	else{
		c = R / n + 1;
		if (c % 2 == 1){
			r = R % n;
		}
		else{
			r = n - R % n + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}
