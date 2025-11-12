#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r, num, h, l, fx;
bool cmp(int x, int y){
	return x > y; 
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	r = a[1];
	for (int i = 2; i <= n*m; i++){
		cin >> a[i];
	}
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++){
		if (a[i] == r){
			num = i; 
		 } 
	}
	l = 1;
	fx = 1;
	while(num > n){
		num -= n;
		fx += 1;
		fx %= 2;
		l++;
	}
	if (fx){
		h = num;
	}
	else{
		h = n-num+1;
	}
	cout << l << " " << h;
	return 0;
} 
