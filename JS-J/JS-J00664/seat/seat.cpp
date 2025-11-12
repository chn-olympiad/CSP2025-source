#include <bits/stdc++.h>
using namespace std;

int n, m, a[107];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	int k = 1;
	for(int i = 2; i <= n * m; i++){
		if(a[i] > a[1]) k++;
	}
	printf("%d %d\n", (k - 1) / n + 1, ((((k - 1) / n) & 1) ? n - (k - 1) % n : (k - 1) % n + 1));
	return 0;
}
