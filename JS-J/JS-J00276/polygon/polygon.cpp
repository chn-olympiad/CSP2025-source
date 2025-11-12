#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int n;
int len[5005];
long long tolen[5005];
long long cnt;
long long mah(int tal, int st, int num, long long sum, int end){
	if(num == 0){
		if(sum > tal)
			cnt++;
		cnt %= MOD;
	}
	for(int i = st + 1; i < end; i++){
		mah(tal, i, num - 1, sum + len[i], end);
	}
	return cnt % MOD;
}
long long jc(int x){
	long long sum = 1;
	int cnt = 1;
	for(int i = n; cnt <= x; i--){
		cnt ++;
		sum = sum * i;
		sum %= MOD;
	}
	return sum;
}
long long cf(int x){
	long long ans = 1;
	for(int i = 1; i <= x; i++){
		ans *= i;
		ans %= MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	bool f = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &len[i]);
		if(len[i] != len[1]){
			f = 1;
		}
	}
	long long ans = 0;
	if(f == 0) {
		for(int i = 3; i <= n; i++){
			long long x = jc(i) % MOD;
			long long y = cf(i) % MOD;
			ans = (ans + x / y) % MOD;
		}
		printf("%lld", ans % MOD);
		return 0;
	}
	sort(len + 1, len + 1 + n);
	for(int i = 1; i <= n; i++){
		tolen[i] = tolen[i - 1] + len[i];
	}
	for(int i = 3; i <= n; i++){
		for(int j = 2; j < i; j++){
			if(tolen[i] - tolen[i - j - 1] < 2 * len[i]){
				continue;
			}
			cnt = 0;
			ans = (ans + mah(2 * len[i], 0, j, len[i], i)) % MOD;
		}
	}
	printf("%lld", ans % MOD);
	return 0;
}
