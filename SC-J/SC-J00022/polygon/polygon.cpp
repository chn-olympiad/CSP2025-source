#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e5 + 11;
const LL Big = 998244353;
LL n,cnt;
LL a[N];
LL qpow(LL x,LL y){
	LL ans = 1;
	while(y){
		if((y & 1) == 1) ans = (ans % Big * x % Big) % Big;
		y >>= 1;
		x = x % Big * x % Big;
	}
	return ans % Big;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(LL i=1;i<=n;i++){
		read(a[i]);
		if(a[i] == 1) cnt ++;
	}
	if(cnt == n){
		LL ans = 0;
		for(LL i=4;i<=n;i++){
			LL tot = qpow(2,i - 1) % Big;
			tot --;
			tot -= (i - 1);
			tot -= ((i - 1) * (i - 2) / 2);
			tot = (tot + Big) % Big;
			ans = (ans % Big + tot % Big) % Big;
		}
		print(ans % Big);
		return 0;
	}
	sort(a + 1,a + 1 + n);
	LL ans = 0;
	for(LL i=3;i<=n;i++){
		for(LL j=0;j<(1<<(i-1));j++){
			LL tot = 0;
			for(LL k=0;k<=(i-1);k++){
				if(((j >> k) & 1) == 1) tot += a[k + 1];
			}
			if(tot > a[i]) ans ++;
			ans %= Big;
		}
	}
	print(ans);
	return 0;
}
