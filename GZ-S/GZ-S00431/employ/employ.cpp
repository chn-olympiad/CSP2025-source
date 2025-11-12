//GZ-S00431 贵阳雅礼高级中学（贵阳市第九中学） 赵锦鹏 
#include <bits/stdc++.h>
#define maxn 505
#define modn 998244353
using namespace std;

unsigned int dp[2][maxn][maxn];
int n,m;
int c[maxn];
int outN;

unsigned long long lm(int n)
{
	long long ans=1;
	for (int i=1;i<=n;i++)
	{
		ans*=n;
		ans%=modn;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char inp;
	for (int i=0;i<n;i++)
	{
		cin>>inp;
		if (inp=='0') outN++;
	}
	if (outN==0)
	{
		cout<<lm(n);
	}
	return 0;
}
