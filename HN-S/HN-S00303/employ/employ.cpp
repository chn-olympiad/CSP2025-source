#include<bits/stdc++.h>
#define maxn 505
#define int long long
#define mod 998244353
char s[maxn];
int n,m,k,dp[maxn][maxn][maxn],c[maxn],fac[maxn];
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
	while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)x = -x,putchar('-');
	static char sta[30];int top = 0;
	do sta[top++] = x%10,x/=10;while(x);
	while(top)putchar(sta[--top]^'0');
	putchar('\n');
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	scanf("%s",s+1);
	for(int i = 1;i<=n;++i)c[i] = read();
	for(int i = 1;i<=n;++i)
		if(s[i] == '1')++k;
	if(k == n)
	{
		fac[0] = 1;
		for(int i = 1;i<=n;++i)
			fac[i] = fac[i-1]*i%mod;
		write(fac[n]);
	}
	return 0;
}
//3 2
//111
//1 1 2
