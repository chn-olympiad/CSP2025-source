#include <bits/stdc++.h>
#define LL long long
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
using namespace std;
const int N = 505;
const LL mod = 998244353;
int n , m , c[N] , a[N] , vis[N];
LL ans;
char s[N];
LL fac[N];
void pre () {
	fac[0] = 1;
	fu (i , 1 , 500) fac[i] = fac[i - 1] * i % mod;
}
void dfs (int x) {
	if (x > n) {
		int sum = 0;
		fu (i , 1 , n) {
			if ((i - 1 - sum) >= c[a[i]]) continue;
			sum += (s[i] == '1');
		}
		ans += (sum >= m);
	}
	else {
		fu (i , 1 , n) {
			if (vis[i]) continue;
			vis[i] = 1 , a[x] = i;
			dfs (x + 1);
			vis[i] = a[x] = 0;
		}
	}
}
int main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	int p = 0;
	pre ();
//	cout << fac[15];
//	return 0;
	scanf ("%d%d" , &n , &m);
	scanf ("%s" , s + 1);
	fu (i , 1 , n) {
		p += (s[i] == '1');
	}
	fu (i , 1 , n) {
		scanf ("%d" , &c[i]);
	}
	if (n <= 10) {
		dfs (1);
		printf ("%lld" , ans);
		return 0;
	}
	if (p == n) {
		printf ("%lld" , fac[n]);
		return 0;
	}
	return 0;
}
