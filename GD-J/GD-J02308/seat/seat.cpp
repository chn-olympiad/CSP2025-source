#include<bits/stdc++.h>
using namespace std;
int n, m, x, a[105], c, r, p = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
		if (i == 1) x = a[i];
	}
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i--){
		if ((n * m - i) % n == 0) c++;
		r += p;
		if (r == n + 1 || r == 0){
			p = -p;
			r += p;
		}
		if (x == a[i]) break;
	}
	printf("%d %d", c, r);
	return 0;
}
