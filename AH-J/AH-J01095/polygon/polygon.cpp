#include<bits/stdc++.h>
using namespace std;
unsigned long long a[5010], n, ans = 1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%llu", &n);
	for(unsigned long long i = 1;i <= n;i++){
		scanf("%llu", a + i);
		ans = (ans * 2) % 998244353;
	}
	printf("%llu", ans);
	return 0;
}
