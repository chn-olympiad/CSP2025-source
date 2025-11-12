#include<cstdio>
#include<algorithm>

using namespace std;
int n, m;
int s[15][15];
int a[105];
bool cmp(const int a, const int b) {
	return a >= b;
}
int c, r;
int p;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n*m;i++) {
		scanf("%d", &a[i]);
	}
	int R = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i < n*m;i++) {
		if(a[i] == R) {
			p = i;
			break;
		}
	}
	if(p%n == 0) c = p/n;
	else c = p/n+1;
	if(c%2 == 0) {
		if(p%n == 0) r = 1;
		else r = n+1-(p%n);
	}
	else {
		if(p%n==0) r = n;
		else r = (p%n);
	}
	
	printf("%d %d", c, r);
	return 0;
}