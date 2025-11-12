#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
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
int n, k;
int s[N], dp[N], f[N], h[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(h, -1, sizeof(h));
	n = read(), k = read();
	for(int i = 1; i <= n; ++i)
	  s[i] = s[i - 1] ^ read();
	h[0] = 0;
	for(int i = 1; i <= n; ++i){
		dp[i] = h[s[i] ^ k] + 1;
		f[i] = max(dp[i], f[i - 1]);
		h[s[i]] = max(h[s[i]], f[i]);
//		cerr << dp[i] << ' ';
	}
//	cerr << '\n';
	write(f[n]);
	return 0;
}
