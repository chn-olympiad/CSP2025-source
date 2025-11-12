#include <bits/stdc++.h>
using namespace std;

int a[105];
int n, m;
int c, r;

bool cmp(const int &x, const int &y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n*m; i++) scanf("%d", &a[i]);

	int x = a[1];
	int w;

	sort(a+1, a+n*m+1, cmp);

	for(int i = 1; i <= n*m; i++){
		if(x == a[i]){
			w = i;
			c = ceil(i*1.0/n);
			if(i%n == 0) r = n;
			else r = i%n;
			if(c%2 == 0) r = n-r+1;
		}
	}

	printf("%d %d", c, r);

	return 0;
}