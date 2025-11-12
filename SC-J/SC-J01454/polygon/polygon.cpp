#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, mod = 998244353;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
		  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
	  write(x / 10);
	putchar(x % 10 + '0');
}
int n, mx, ans;
int a[N], dp[2][2][N], f[2];
inline void getadd(int &x, int y){
	x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i){
		int now = i & 1, pre = now ^ 1;
		if(i > 2){
			getadd(ans, f[pre]);
			for(int j = a[i] + 1; j <= mx; ++j)
			  getadd(ans, dp[pre][1][j]);
		}
		f[now] = f[pre] * 2ll % mod;
		for(int num = 0; num < 2; ++num)
		  for(int j = 1; j <= mx; ++j)
		    dp[now][num][j] = dp[pre][num][j];
		getadd(dp[now][0][a[i]], 1);
		for(int num = 0; num < 2; ++num){
			int nxt = num | 1;
			for(int j = 1; j <= mx; ++j){
				if(!dp[pre][num][j])
				  continue; 
				if(j + a[i] > mx)
				  getadd(f[now], dp[pre][num][j]);
				else
				  getadd(dp[now][nxt][j + a[i]], dp[pre][num][j]);
			}
		}
//		cerr << f[now] << '\n';
	}
	write(ans);
	return 0;
}
