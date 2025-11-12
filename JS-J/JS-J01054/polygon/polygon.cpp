#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n, a[5001], ans = 0;

void check(int n){
	for (int i = 3; i <= n; i++){
		long long sum = 1;
		
		for (int j = 1; j <= i; j++){
			sum = sum * (n - j + 1) / j % M;
		}
		ans = (ans + sum) % M;
	}
	
}

void dp(int step, int sum){
	if (step > n) return ;
	if (sum > a[step]) {
		ans++;
		ans %= M;
	}
	dp(step + 1, sum);
	dp(step + 1, sum + a[step]);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	else if (n <= 21){
		dp(1, 0);
		cout << ans;
	}
	else {
		check(n);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
