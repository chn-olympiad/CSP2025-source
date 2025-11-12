#include <bits/stdc++.h>
using namespace std;
int a[1145], n, m, r, sum, x, y;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++){
		if (a[i] == r) {
			sum = i;
			break;
		}
	}
	if (sum % n == 0) x = sum / n;
	else x = sum / n + 1;
	if (x & 1) y = sum % n;
	else y = n - sum % n + 1;
	if (y == 0) y = n;
	if (y > n) y = 1;
	cout << x << " " << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
