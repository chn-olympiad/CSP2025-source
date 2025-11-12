#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(seat.in, r, stdin);
	freopen(seat.out, w, stdout);
	int n, m, x, nx = 1, mx = 1, s[120];
	cin >> n >> m >> x;
	for (int i = 1; i < n * m; i++){
		cin >> s[i];
		if (s[i] > x){
			if (nx == n){
				nx = 1;
				mx += 1;
			}
			else{
				nx += 1;
			}
		}
	}
	cout << mx << ' ' << nx;
	return 0;
}

