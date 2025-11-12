#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>inline void read(T &x){
	char c;int sign = 1;x = 0;
	do{c = getchar();if(c == '-') sign = -1;} while (! isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();} while (isdigit(c));
	x *= sign;
}
template <typename T>inline void wr(T x){
	if (x < 0){putchar('-');x = -x;};
	if (x > 9) wr(x / 10);
	putchar((x % 10) | 48);
}

const int N = 5e5 + 5;
int n,k;
int a[N];
int ans,xo,r;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	read(n);read(k);
	for ( int i = 1; i <= n; i ++){
		read(a[i]);
	}
	for ( int i = 1; i <= n; i ++){
		xo = xo ^ a[i];
		if (xo == k){
			xo = 0;
			ans ++;
			r = i;
			continue;
		}
		int sum = 0;
		for ( int j = i; j > r; j --){
			sum = sum ^ a[j];
			if (sum == k){
				ans ++;
				r = i;
				xo = 0;
				break;
			}
		}
	}
//	wr(n);putchar(' ');wr(k);
	wr(ans);
	return 0;
}
