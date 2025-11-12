#include <bits/stdc++.h>

using namespace std;

int main (){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n,m;
	int c,r;
	int a[105],b[5];
	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n * m;i++)
	scanf ("%d", &a[i]);
	b[1] = a[1];
	for (int i = 1;i <= n * m;i++)
	for (int j = 1;j <= n * m - i;j++)
	if (a[j] <= a[j + 1]){
		int t = a[j];
		a[j] = a[j + 1];
		a[j + 1] = t;
	}
	for (int i = 1;i <= n * m;i++){
		if (a[i] == b[1]){
			if (i % n == 0)
			c = i / n;
			else
			c = i / n + 1;
		}
		if (c % 2 == 1){
		if (i % m == 0){
			r = i / m;
		}else{
			r = i / m + 1;
		}
	}else{
			if (i % m == 0){
			r = n - i / m + 1;
		}else{
			r = n - i / m + 1;
		}
	}
}
printf ("%d %d", c, r);
	return 0;
} 
