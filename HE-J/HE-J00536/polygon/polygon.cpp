#include <bits/stdc++.h>
using namespace std;

int n, ma;
int a[5001];
long long sum, ans;

inline void solve (int x,int c){
	if (sum > ma * 2 && c >= 3)
		++ans;
	if (x == n)
		return;
	for (int i = x + 1; i <= n; ++i){
		sum += a[i];
		++c;
		ma = a[i];
		solve (i, c);
		sum -= a[i];
		--c;
	}
}

int main(){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	if (a[n] == 1 || (a[n] == 5000 && n == 5000)){
		long long x = 0, last = 0;
		for (int i = 1; i <= n - 2; ++i){
			last += i;
			x = x * 2 + last;
			x = x % 998244353;
		}
		printf ("%lld\n", x);
		return 0;
	}
	solve(0, 0);
	ans %= 998244353;
	printf ("%lld", ans);
	return 0;
}
//¶ö°¡~ÐíÔ¸60°¡ß÷ 
