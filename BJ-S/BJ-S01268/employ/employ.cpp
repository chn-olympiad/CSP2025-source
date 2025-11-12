#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int c[510],dp[1100][20],ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,f=1,f2=1,i,j,k;
	cin>>n>>m;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]!='1')
			f=0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
			f2=0;
	}
	/*if(f)
	{
		ans=1;
		for(i=1;i<=n;i++)
			ans=1ll*ans*i%P;
		cout<<ans;
		return 0;
	}*/
	if((f==0||f2==0)&&m==n)
	{
		cout<<0;
		return 0;
	}
	int l=(1<<n);
	dp[0][0]=1;
	for(i=1;i<l;i++)
	{
		int cnt=0;
		for(j=0;j<n;j++)
		{
			if(i&(1<<j))
				cnt++;
		}
		for(j=0;j<=cnt;j++)
		{
			for(k=0;k<n;k++)
			{
				if(i&(1<<k))
				{
					if(s[cnt-1]=='0'||(j-1)>=c[k+1])
						dp[i][j]=(dp[i][j]+dp[i-(1<<k)][j-1])%P;
					else if(c[k+1]>j)
						dp[i][j]=(dp[i][j]+dp[i-(1<<k)][j])%P;
				}
			}
		}
	}
	for(i=0;i<=n-m;i++)
		ans=(ans+dp[l-1][i])%P;
	cout<<ans;
	return 0;
}
