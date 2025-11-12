#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int x = 0, ff = 1;
	char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar(); 
	if(c == '-') c = getchar(), ff = -1;
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * ff;
}
const int N = 510, mod = 998244353;
int n, m, a[N], b[N], /*cnt[N][2],*/ lim[N], cnt[N], num[N];
LL f[N][N][N];
char s[N];
void add(LL& X, LL Y) {
	X = (X + Y) % mod;
}
//bool check(int i, int B, int c1){
//	int b1 = cnt[i][0] - B, 
//} 
int p[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(); m = read();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i){
		a[i] = s[i] == '1';
//		sum1[i] = sum1[i - 1] + a[i];
//		sum2[i] = sum2[i - 1] + 1 - a[i];
	}
	for(int i = 1; i <= n; ++i){
		b[i] = read();
//		lim[i] = lower_bound(sum2 + 1, sum2 + n + 1, b[i]) - sum2 - 1;
//		cnt[lim[i]]++;
	}
//	for(int i = n; i; --i)
//		num[i] = num[i + 1] + cnt[i];
	int S = 1, ans = 0;
	for(int i = 1; i <= n; ++i){
		p[i] = i;
		S *= i;
	}
	for(int o = 1; o <= S; ++o){
		int res = 0, g = 0;
		for(int i = 1; i <= n; ++i){
			int x = p[i];
			if(g < b[x] && s[i] == '1')
				++res;
			else
				++g;
		}
//		cerr << res << endl;
		ans += res >= m;
		next_permutation(p + 1, p + n + 1);
	}
	cout << ans << endl;
//	for(int i = 0; i <= n; ++i)
//		f[n + 1][0][i] = 1;
//	for(int i = n; i; --i)
//		for(int j = 0; j <= n; ++j)
//			for(int k = 0; k <= n; ++k){
//				if(a[i]) {			// employed
//					add(f[i][j + 1][k], f[i][j][k] * (num[k] - ));
//					
//				}
//			} 
	return 0;
} 
