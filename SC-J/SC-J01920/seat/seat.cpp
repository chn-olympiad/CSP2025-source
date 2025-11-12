#include <bits/stdc++.h>
using namespace std;

int n, m, a[110], x;

int main (){
//	freopen ("seat.in", "r", stdin);
//	freopen ("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++){
		scanf ("%d", &a[i]);
	}
	x = a[1];
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++){
		if (a[i] == x){
			x = n * m - i + 1;
			break;
		}
	}
	if (x / n % 2 == 0){
		if (x % n >= 1){
			printf ("%d %d", x / n + 1, x % n);
		}
		else
			printf ("%d %d", x / n, 1);
	}
	else{
		if (x % n >= 1){
			printf ("%d %d", x / n + 1, n - x % n + 1);
		}
		else
			printf ("%d %d", x / n, n);
	}
	return 0;
}