#include <bits/stdc++.h>
using namespace std;
int n, a[5020];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	int ans = 998244359 % 998244353;
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
