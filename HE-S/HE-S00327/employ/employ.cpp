#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>inline void read(T &x){
	char c;int sign = 1;x = 0;
	do{c = getchar();if (c == '-') sign = -1;}while (! isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();} while (isdigit(c));
	x *= sign;
}
template <typename T>inline void wr(T x){
	if (x < 0){putchar('-');x = -x;}
	if (x > 9) wr(x / 10);
	putchar((x % 10) | 48);
}
const int mod = 998244353;
int n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	int ans = 1;
	for ( int i = 1; i <= n; i ++){
		ans = ans * i % mod;
	}
	cout << ans % mod;
	return 0;
}
