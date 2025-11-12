#include<bits/stdc++.h>
using namespace std;
int n, m, r, x = 0, a, b;
int c[210];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	for(int i = 2; i <= n * m; i++){
		cin >> c[i];
		if(c[i] > r){
			x++;
		} 
	}
    x += 1;
	if(x % n == 0){
		a = x / n;
		if(a % 2 != 0){
		    b = n;
		}else{
			b = 1;
		}
	}else{
		a = x / n + 1;
		if(a % 2 != 0){
		    b = x % n;
		}else{
			b = n + 1 - x % n;
		}
	}
	cout << a << " " << b;
	return 0;
} 
