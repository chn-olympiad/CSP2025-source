#include <stdio.h>
#include <algorithm>
using namespace std;
#define int long long
#define MAXN 1005
#define MOD 998244353

int n, m;
int fac[MAXN];
int inv[MAXN];
int s[MAXN], c[MAXN], cnt[MAXN], cntsum[MAXN];
bool xzA = true;
int qpow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
void init(){
	fac[0] = 1;
	for(int i = 1; i <= n + 10; i++){
		fac[i] = fac[i - 1] * i % MOD;
	}
	inv[n + 10] = qpow(fac[n + 10], MOD - 2);
	for(int i = n + 9; i >= 0; i--){
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
}
int A(int a, int b){
	return fac[a] * inv[a - b] % MOD;
}
char inp(){
	char ch = getchar();
	while(ch < '0' || ch > '9')
		ch = getchar();
	return ch;
}
signed main(void){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	init();
	for(int i = 1; i <= n; i++)
		s[i] = inp() - '0';
	for(int i = 1; i <= n; i++){
		if(s[i] == 0)
			xzA = false;
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", c + i);
		cnt[c[i]]++;
	}
	for(int i = 1; i <= n; i++){
		cntsum[i] = cntsum[i - 1] + cnt[i];
	}
	if(m == 1){
		sort(c + 1, c + n + 1);
		int pt = 1;
		long long ans = 0;
		vector<int> ps;
		for(int i = 1; i <= n; i++){
			if(s[i] == 1)
				ps.push_back(i);
		}
		for(int i = 0; i < ps.size(); i++){
			while(c[pt] < ps[i])
				pt++;
			int cur = 1;
			for(int j = 0; j < ps.size(); j++){
				if(j == i)
					continue;
				if(c[pt] >= ps[j])
					cur = cur * cntsum[ps[j] - 1] % MOD;
				else
					cur = cur * (cntsum[ps[j] - 1] - 1) % MOD;
			}
			cur = cur * A(n - ps.size(), n - ps.size()) % MOD;
			ans = (ans + cur) % MOD;
		}
		printf("%lld\n", ans);
		return 0;
	}
	else if(xzA){
		sort(c + 1, c + n + 1);
		if(m < n){
			if(cnt[0] == 0 || cnt[0] > n - m){
				printf("0");
				return 0;
			}
			
		}
		else{
			if(cnt[0]){
				printf("0");
				return 0;
			}
			else{
				printf("%lld", fac[n]);
				return 0;
			}
		}
	}
	else if(m == n){
		if(cnt[0]){
			printf("0");
			return 0;
		}
		else{
			printf("%lld", fac[n]);
			return 0;
		}
	}
	printf("0");
	return 0;
}

/*
3 2
101
1 1 2
*/
