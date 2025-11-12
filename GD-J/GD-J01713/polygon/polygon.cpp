#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 5005,MOD = 998244353;
int n;
int a[N];
long long dp[N][N];//dpi,j bs 1-i sum >= j geshu
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for (int i = 1; i <= n; i++) a[i]=read();
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 5005; j++)
		{
			dp[i][j]+=dp[i-1][j];
			dp[i][j]+=dp[i-1][max(0,j-a[i])];
			dp[i][j]%=MOD;
		}
	}
	long long ans = 0;
	for (int i = 3; i <= n; i++) ans=(ans+dp[i-1][a[i]+1])%MOD;
	write(ans);
	return 0;
}

