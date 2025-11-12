#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, r, pos = 1;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> r;
	for (int i = 2; i <= n * m; i++){
		int x;
		cin >> x;
		if (x > r){
			pos++;
		}
	}
	if (pos % n == 0){
		y = pos / n;
		if (y % 2 == 0){
			x = 1;
		}
		else{
			x = n;
		}
	}
	else{
		y = pos / n + 1;
		if (y % 2 == 0){
			x = n - (pos % n) + 1;
		}
		else{
			x = pos % n;
		}
	}
	cout << y << " " << x << "\n";
	
	return 0;
}
