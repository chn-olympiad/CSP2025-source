#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int bgr = 0, smlr = 0, n, m, r;
	cin >> n >> m >> r;
	for(int i = 1; i < n * m; i++){
		int x;
		cin >> x;
		if(x < r) smlr++; else bgr++;
	}
	int x = (bgr + n) / n, y;
	if(x % 2 == 1) y = bgr + 1 - n * (x - 1); else y = n - (bgr + 1) + n * (x - 1) + 1;
	cout << x << " " << y;
	return 0;
} 
