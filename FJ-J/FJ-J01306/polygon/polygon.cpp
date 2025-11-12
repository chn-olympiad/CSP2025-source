#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010, M = 5000, Mod = 998244353;

int n;
int a[N];
int f[N][N], ans;

int q_mul(int a, int b){
	int c = 1;
	for(b; b; b >>= 1, a = (a * a) % Mod) if(b & 1) c = (c * a) % Mod;
	return c;
}

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	
	return f * x;
}

void solve(){
	
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + 1 + n);
	
	for(int j = 0; j <= M; ++j) f[2][j] = a[1] <= j;
	
	for(int i = 3; i <= n; ++i){
		for(int k = 0; k <= M; ++k){
			for(int j = 1; j < i; ++j){
				if(k >= a[j]) f[i][k] = (f[i][k] + f[j][k - a[j]] + 1) % Mod;
			}
		}
	}
	
	
	for(int i = 3; i <= n; ++i){
		ans = ((((ans + q_mul(2, i - 1)) % Mod + Mod - 1) % Mod) - f[i][a[i]]) % Mod;
//		printf("在1~%d中选择若干数，有%/*d种方案小于等于%d\n", i - 1, f[i][a[i]], a[i]);
//		printf("在1~%d中选择若干数，有%*/d种方案大于%d\n", i - 1, q_mul(2, i - 1) - 1 - f[i][a[i]], a[i]);
	}
	printf("%lld\n", ans);
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	solve();
	return 0;
}


/*
对ai排序
求1~i中选择若干数，和大于ai的方案数的和

*/
