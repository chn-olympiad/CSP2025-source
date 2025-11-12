#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans;
const long long mod=998244353;
bool book[505];
string s;
void dfs(long long cnt,long long fail,long long success)
{
	if(fail>n-m)
	{
		return ;
	}
	if(cnt==n+1)
	{
		if(success>=m)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			if(fail>=a[i]||s[cnt-1]=='0')
			{
				dfs(cnt+1,fail+1,success);
			}
			else
			{
				dfs(cnt+1,fail,success+1);
			}
			book[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
