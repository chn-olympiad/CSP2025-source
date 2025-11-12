#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 120;
int n, m, k, a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> k;
	a[1] = k;
	for(int i = 2; i <= n * m; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1, z = 2;
	while(a[z] >= k){
		if(y % 2 != 0){
			if(x == n){
			y++;
		    } else x++;
		} else {
			if(x == 1){
				y++;
			} else x--;
		}	
		z++;
	}
	cout << y << " " << x;
	return 0;
}
