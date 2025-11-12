#include<bits/stdc++.h>
using namespace std;
char c[1005];
int a[10005];
const int mod=998244353;
long long ans=0;
bool cho[1005];
int n,m;
void dfs(int x,int y)
{
	if(y+n<m+x)
	{
		return;
	}
	if(y>=m)
	{
		long long nans=1;
		for(int i=1;i<=n-x;i++)
		{
			nans*=i;
		}
		ans+=nans;
		return;
	}
	if(x==n)
	{
		//cout<<y<<endl;
		if(y>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!cho[i])
		{
			cho[i]=1;
			if(c[x+1]==0)
			{
				dfs(x+1,y);
			}
			else
			{
				if(a[i]<=x-y)
				{
					dfs(x+1,y);
				}
				else
				{
					dfs(x+1,y+1);
				}
			}
			cho[i]=0;
		}
	}
}
long long dp[505][505];
int t[1005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]-='0';
		if(c[i]==1)
		{
			cnt++;
		}
	}
	if(cnt<m)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n<=18)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(0,0); 
		cout<<ans%mod;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		a[n+1]=1000;
		int j=1,nc=0;
		ans=1;
		for(int i=1;i<=n;i++)
		{
			while(a[j]<i)
			{
				j++;
			}
			if(c[i]==1)
			{
				ans=ans*(j-1-nc);
				//cout<<j-1-nc<<endl;
				ans%=mod;
				nc++;
			}
		}
		for(int i=1;i<=n-cnt;i++)
		{
			ans*=i;
			ans%=mod;
		}
		long long su=1;
		for(int i=1;i<=n;i++)
		{
			su*=i;
			su%=mod;
		}
		cout<<(su-ans+mod)%mod<<endl;
		return 0;
	}
	cout<<0;
	return 0;
}
