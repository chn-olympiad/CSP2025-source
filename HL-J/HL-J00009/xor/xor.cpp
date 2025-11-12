#include<stdio.h>
int n, k, a[500000], x = 0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		if(a[i] == 0)
		n--, i--;
	}
	for(int i = 2; i <= n; i += 2)
	x += n / i;
	printf("%d", x);
	return 0;
}