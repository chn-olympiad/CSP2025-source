#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, ans = 1, x, y;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
		if(i != 1 && a[i] > a[1]){
			ans++; 
		}
	}
	if(ans%n == 0){
		x = ans/n;
		y = n;
	}
	else{
		x = ans/n + 1; 
		y = ans % n;
	} 
	if(x % 2 == 1){
		cout << x << " " << y;
	}else{
		cout << x << " " << n - y + 1;
	}	
	return 0;
} 