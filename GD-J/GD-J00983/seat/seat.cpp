#include<bits/stdc++.h>
using namespace std;

int n, m, a[101];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int p = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++)
		if(a[n * m - i + 1] == p){
			int x = (i + n - 1) / n, y = 0;
			if(x & 1){
				if(i % n == 0)
					y = n;
				else
					y = i % n;
			}
			else{
				if(i % n == 0)
					y = 1;
				else
					y = n - i % n + 1;
			}
			printf("%d %d\n", x, y);
			break;
		}
	return 0;
}
