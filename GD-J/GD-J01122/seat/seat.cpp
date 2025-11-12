#include<bits/stdc++.h>
#define dbg(R) cerr<<#R<<" "<<R
using namespace std;
int R = 1, n, m, r;
int a[15][15]; 

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	for(int i = 2; i <= n * m; i++){
		int x;
		cin >> x;
		if(x > r) R++;
	}
	//dbg(R);
	for(int i = 1; i <= m; i++){
		if(R > n) {
			R -= n;
			continue;
		}
		if(i % 2 == 0) cout << i << " " << n - R + 1;
		else cout << i << " " << R;
		break;
	}
	   return 0;
}

