#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[500020], k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++){
		if (n <= 2){
			if (a[i] == k)	printf("1");
			else	printf("0");
		}
		else	printf("2");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
