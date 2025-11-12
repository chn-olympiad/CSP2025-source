#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int cnt=0;
int p[5005];

int dfs(int x)
{
	if(x>n)
	{
		int sum=0,mn=0;
		for(int i=1;i<=cnt;i++)
		{
			sum+=p[i];
			mn=max(p[i],mn);
		}
		if(sum>mn*2&&cnt>=3) return 1;
		return 0;
	}
	int ss=0;
	p[++cnt]=a[x];
	ss+=dfs(x+1);
	cnt--;
	ss+=dfs(x+1);
	ss%=998244353;
	return ss;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		cout<<dfs(1);
	}
	else
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=998244353;
		}
		ans-=n*(n-1)/2+n+1;
		cout<<ans;
	}
	return 0;
}