#include<bits/stdc++.h>
using namespace std;

int n, m, a[201], x, c, r, num;

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		scanf("%d", a[i]);
	}
	
	x = a[1];
	
	for (int i = 1; i <= n * m - 1; i++){
		for (int j = 1; j <= n * m - 1; j++){
			if (a[j] < a[j + 1]){
				int f = a[j];
				a[j] = a[j + 1];
				a[j + 1] = f;
			}
		}
	}
	
	for (int i = 1; i <= n*m; i++){
		if (a[i] == x){
			num = i;
		}
	}
	
	if (num % n != 0) c = num / n + 1;
	else c = num / n;
	if (c % 2 != 0) r = num % n;
	else r = num - (num % n);
	
	cout << c << r;
	
	return 0;
}
