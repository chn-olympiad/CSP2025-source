#include<bits/stdc++.h>
using namespace std;
long long sum;
int n, a[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) sum += i;
	printf("%lld", sum);
	return 0;
}
