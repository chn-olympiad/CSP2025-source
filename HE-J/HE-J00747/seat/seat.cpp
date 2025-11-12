#include <bits/stdc++.h>
using namespace std;
int a[111];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans, sum;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	ans = a[1];
	for(int i = 1; i <= n*m; i++){
		for(int j = 1; j <= n*m; j++){
			if(a[j] < a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
	for(int i = 1; i <= n*m; i++){
		if(a[i] == ans){
			sum = i;
		}
	}
	int x = 0, y = 0;
	y = sum / n;
	if(sum % n != 0){
		y++;
	}
	if(y % 2 == 0){
		x = n - (sum-1) % n;
	}else{
		x = 1 + (sum-1) % n;
	}
	cout << y << " " << x;
	return 0;
}
