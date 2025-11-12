#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; ){
		if (x % 2){
			y ++;
			i ++;
			if (a[i] == R) {
				cout << x << ' ' << y;
				return 0;
			}
		}
		else {
			y --;
			i ++;
			if (a[i] == R) {
				cout << x << ' ' << y;
				return 0;
			}
		}
		if ((x % 2 && y == n) || (x % 2 == 0 && y == 1)){
			x ++;
			i ++;
			if (a[i] == R) {
				cout << x << ' ' << y;
				return 0;
			}
		}
	}
	return 0;
}
