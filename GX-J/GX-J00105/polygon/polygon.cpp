#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
long long n, a[5005], ans;

void search(int x, int y){
	for(int i = y + 1; i <= n; i++){
		if(a[x] + a[y] > a[i]) ans++;
		ans %= mod;
		a[y] += a[x];
		search(y, i);
		a[y] -= a[x];
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > a[3]){
			printf("1");
		}
		else printf("0");
		return 0;
	}
	if(a[n] == 1){
		for(int i = 3; i < n; i++){
			ans = (ans + (n - i) * n) % mod;
		}
		ans = (ans + 1) % mod;
		printf("%lld", ans);
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			search(i, j);
		}
	}
	printf("%lld", ans % mod);
	return 0;
}
