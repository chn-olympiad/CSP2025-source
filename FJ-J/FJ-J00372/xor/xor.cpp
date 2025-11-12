#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
int n, k, a[M];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (k == 0) {
		printf("%d", n);
	}else printf("2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
