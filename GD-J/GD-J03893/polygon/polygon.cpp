#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
bool put[5005];
bool check()
{
	int m=0,maxx=0,sum=0;
	for(int i=1;i<=n;i++)
		if(put[i])
		{
			m++;
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
	return m>=3&&sum>(maxx*2);
}
void dfs(int p)
{
	if(p==n+1)
	{
		if(check())ans++;
		return;
	}
	put[p]=true;dfs(p+1);
	put[p]=false;dfs(p+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)
	{
		dfs(1);
		cout<<ans;
	}
	else
	{
		for(int ch=3;ch<=n;ch++)
		{
			int add=1;
			for(int j=0;j<ch;j++)
			{
				add*=n-j;
				add/=j+1;
				add%=mod;
			}
			ans=(ans+add)%mod;
		}
		cout<<ans;
	}
	return 0;
}
