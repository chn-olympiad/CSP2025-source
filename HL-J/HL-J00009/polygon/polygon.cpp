#include<stdio.h>
#include<algorithm>
int n, a[3];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d%d%d%d", &n, a, a + 1, a + 2);
	std::sort(a, a + 3);
	printf("%d", a[1] + a[2] > *a);
	return 0;
}