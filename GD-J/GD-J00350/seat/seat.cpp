#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[101];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int r;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int num = 0;
	for (int i = 1; i <= n * m; i++){
		if (r == a[i]){
			num = i;
			break;
		}
	}
	if (num % n == 0) x = num / n;
	else x = num / n + 1;
	if (x % 2 == 1){
		y = num % n;
		if (y == 0) y = n;
	}
	else {
		y = n - num % n + 1;
		if (y == 5) y = 1;
	}
	cout << x << " " << y;
	return 0;
}
