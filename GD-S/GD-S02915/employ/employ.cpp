#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
#define N 505
#define MOD 998244353
#define msg(Args...) fprintf(stderr, Args)
//#define LOCAL

using namespace std;

char s[N];
int c[N];
int vis[N] = {}, ans = 0, n, m;

int fac(int x) {
	int res = 1;
	
	for (int i = 2; i <= x; i++) res = (res * i) % MOD;
	
	return res;
}

void dfs(int x, int pass, int fail) {
	if (x > n) {
//		printf("pass = %d\n", pass);
		ans = (ans + (pass >= m)) % MOD;
		return;
	}
	
	if (pass >= m) { // 下面没有搜的必要了，直接计算 
//		puts("FAC!!!");
		ans = (ans + fac(n - x + 1)) % MOD;
		return;
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = true;
//			printf("%d ", i);
			
			if (fail >= c[i])
				dfs(x + 1, pass, fail + 1);
			else
				dfs(x + 1, pass + (s[x] == '1'), fail + (s[x] == '0'));
				
			vis[i] = false;
		}
}

int main() {
	#ifndef LOCAL
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
	#endif
	
	scanf("%d%d", &n, &m);
	
	int cnt1 = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		cnt1 += s[i] == '1';
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
//		if (c[i]) hava_naixin++;
	}
	
	if (!cnt1 || (cnt1 < m)) {
		printf("0");
//		msg("jurou!!!");
	}
//	else if (cnt1 == n) {
//		
//	}
	else {
//		sort(c + 1, c + 1 + n, greater <int> ());
//		puts("ELSE!!!");
//		msg("ELSE!!!");
		dfs(1, 0, 0);
		printf("%d", ans);
	}
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;	
}
