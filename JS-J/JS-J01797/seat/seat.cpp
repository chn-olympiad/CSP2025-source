#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1000;
int n, m, a[N + 5];

bool cmp(int x, int y){
	return x > y;
}
int ops, pp;
signed main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++ i)
		cin >> a[i];
	ops = a[1];
	sort (a + 1, a + 1 + n * m, cmp);
	
	for (int i = 1; i <= n * m; ++ i){
		if (ops == a[i]) pp = i;
	}

	int x = 1, y = 1, k = 1, kkk = 0;
	while (k != pp){
		if (kkk == 0){
			x ++;
			if (x > n){
				kkk = 1;
				y ++;
				x = n;
			}
			k ++;
		}
		else if (kkk == 1){
			x --;
			if (x < 1){
				kkk = 0;
				y ++;
				x = 1;
			}
			k ++;
		}
		if (k == pp) break;
		//cout << x << " " << y << endl;
	}
	cout << y << " " << x << endl;
	return 0;
}
/*
 3 3
94 95 96 97 98 99 100 93 92
*/
