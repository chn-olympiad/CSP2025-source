#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;
long long n,m,ans,c[501],vis[501],a[501];
string s;
void dfs(long long dep)
{
	if(dep>n)
	{
		long long sum=0;
		long long cnt[501]={0};
		for(long long i=0;i<s.length();i++)
		{
			if(s[i]=='0')
			{
				for(long long j=i+2;j<=n;j++)cnt[a[j]]++;
			}
			else
			{
				if(cnt[a[i+1]]>=c[a[i+1]])
				{
					for(long long j=i+2;j<=n;j++)cnt[a[j]]++;
				}
				else sum++;
			}
		}
		if(sum>=m)ans++,ans%=mod;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1,a[dep]=i;
			dfs(dep+1);
			vis[i]=0,a[dep]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
