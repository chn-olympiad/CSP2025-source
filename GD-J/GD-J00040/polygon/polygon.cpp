#include <bits/stdc++.h>
using namespace std;
const long long P=998244353;
int st[5005];
long long dp[5005][5005];
long long c[5005][5005];
long long sum_box[5005];
int main()
{
	bool f1=1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> st[i];
		if(st[i]!=1)f1=0;
	}
	sort(st+1,st+n+1);
	if(n<=3)
	{
		if(st[2]+st[3]+st[1]>2*st[3])cout << 1;
		else cout << 0;
		return 0;
	}
	if(f1)
	{
		c[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			c[i][0]=1;
			for(int j=1;j<=i;j++)
			{
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
				//cout << c[i][j] <<  " ";
			}
			//cout << endl; 
		}
		long long sum=0;
		for(int i=3;i<=n;i++)
		{
			sum=(sum+c[n][i])%P;
		}
		cout << sum;
		return 0;//2µÄn´Î·½ 
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-st[i]>=0)dp[i][j]+=dp[i-1][j-st[i]];
			dp[i][j]%=P;
		}
	}
	for(int i=1;i<=5000;i++)
	{
		sum_box[i]=sum_box[i-1]+dp[n][i];
		sum_box[i]%=P;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(sum_box[st[i]]);
		cnt%=P;
	}
	long long mul=1;
	for(int i=1;i<=n;i++)
	{
		mul*=2;
		mul%=P;
	}
	int ans=mul-cnt;
	if(ans<0)ans+=P;
	cout << ans;
	return 0;
}
