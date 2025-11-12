#include <bits/stdc++.h> 
typedef long long ll;   
using namespace std; 

const int N = 505; 
const ll mod = 998244353; 

int n, m, c[N], a[N], tmp, cnt;   

char s[N];  

void BAOLI() { 
	ll ans = 0; 
	do {
		tmp = 0, cnt = 0; 
		for(int i = 1; i <= n; i++) {
			if(tmp >= c[a[i]]) {
				tmp++; 
				continue; 
			}
			if(s[i] == '1') cnt++; 
			else tmp++; 
		} 
		if(cnt >= m) {
			ans++;
			ans %= mod;   
		} 
	} while(next_permutation(a + 1, a + n + 1));  
	printf("%lld\n", ans);  
	return; 
} 

void GetA() { 
	int cnt0 = 0; 
	for(int i = 1; i <= n; i++) {
		if(c[i] == '0') cnt0++; 
	} 
	if(n - cnt0 < m) printf("0\n"); 
	else {
		ll ans = 1; 
		for(ll i = 1; i <= n; i++) {
			ans = ans * i % mod; 
		} 
		printf("%lld\n", ans); 
	}
	return; 
}

int main() {
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout);   
	scanf("%d %d", &n, &m); 
	scanf("%s", s + 1); 
	for(int i = 1; i <= n; i++)	{
		scanf("%d", &c[i]); 
		a[i] = i; 
	} 
	BAOLI(); return 0; 
//	bool flagA = 1; 
//	for(int i = 1; i <= n; i++) {
//		if(s[i] == '0') flagA = 0;  
//	} 
//	if(flagA) { GetA(); return 0; } 
//	printf("0\n"); 
	return 0;     
}
