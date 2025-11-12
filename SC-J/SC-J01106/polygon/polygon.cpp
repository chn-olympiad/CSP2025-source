#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c^48),c = getchar();
	return x * f;
}
const int N = 5005,Q = 998244353;
int n,a[N],m;
int f[N][4][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++)	a[i] = read(),m = max(m,a[i]);
	sort(a+1,a+1+n);
	f[0][0][0] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= 3;j++)
			for(int k = 0;k <= m;k++){
				f[i][j][k] = f[i-1][j][k];
				if(j && k >= a[i])	(f[i][j][k] += f[i-1][j-1][k - a[i]]) %= Q;
				if(j == 3 && k >= a[i])	(f[i][j][k] += f[i-1][j][k - a[i]]) %= Q;
//				if(f[i][j][k])	printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
			}
	ll ans = 0;
	ll num = 1;
	for(int i = 1;i <= n;i++)	(num *= 2) %= Q;
	num = (num - 1 - n - n * (n-1) / 2);
	num = (num % Q + Q) % Q;
	for(int i = 1;i <= n;i++)
		for(int j = 2;j <= 3;j++)
			for(int k = 0;k <= a[i];k++)	(ans += f[i-1][j][k]) %= Q;
//	printf("%lld - %lld\n",num,ans);
	ans = (num - ans + Q) % Q;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
9:17 AK
*/