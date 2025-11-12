#include<bits/stdc++.h>
using namespace std;
int n, m, k = 1, a, r, x, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	for(int i = 1;i < n * m;i++){
		cin >> a;
		if(r < a){
			k++;
		}
	}
	if(k % n == 0){
		x = k / n;
	}
	else{
		x = k / n + 1;
	}
	if(x % 2 == 1){
		y = k - m * (x - 1);
	}
	else{
		y = m - k + m * (x - 1) + 1;
	}
	cout << x << " " << y;
	return 0;
}
