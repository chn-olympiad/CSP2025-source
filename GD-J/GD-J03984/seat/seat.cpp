#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, y;
	cin >> n >> m;
	cin >> a[1];
	int x = a[1];
	for (int i = 2; i <= n*m; i++){
		cin >> a[i];
	}
	sort(a+1, a+m*n+1, cmp);
	for (int i = 1; i <= m*n; i++){
		if (a[i] == x){
			y = i;
		}
	}
	for (int i = 1; i <= m; i++){
		if (i*n >= y && y > (i-1) * n){
			if (i % 2 == 0){
				cout << i << " " << y-(i-1)*n;
				return 0;
			}
			else{
				cout << i << " " << y-(i-1)*n;
				return 0;
			}
		}
	}	
	return 0;
}
