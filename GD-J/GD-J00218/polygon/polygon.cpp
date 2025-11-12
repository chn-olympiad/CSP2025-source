#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n;
int a[10001];
int dp[2][100001];
int now;
int ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		now^=1;
		for(int i=0;i<=10001;i++)
		{
			dp[now][i]=dp[now^1][i];
		}
		dp[now][a[i]]++;
		dp[now][a[i]]%=MOD;
		int sum=0;
		for(int j=a[i]+1;j<=10001;j++)
		{
			ans=(ans+dp[now^1][j])%MOD;
			sum+=dp[now^1][j];
		}
		//cout<<sum<<endl;
		for(int j=0;j<=10001;j++)
		{
			int tmp=j+a[i];
			if(tmp>10001)
			{
				tmp=10001;
			}
			dp[now][tmp]=(dp[now^1][j]+dp[now][tmp])%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
捕鼠夹：
#include<bits\stdc++.h>
int mian()
//freopen("polygon.in","r",stdin);
我要上CSP-J迷惑行为大赏 
I LOVE CCF 
*/
