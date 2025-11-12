#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],d[510];string s;bool v[510];
long long ans;
void dfs(int cnt)
{
	if(cnt>n)
	{
		int f=0,c=0;
		for(int i=1;i<=n;i++)
		{
			if(f>=d[i]||s[i-1]=='0')
			{
				f++;
			}
			else c++;
		}
		if(c>=m) ans=(ans+1)%998244353;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			d[cnt]=a[i];
			v[i]=1;
			dfs(cnt+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;for(int i=1;i<=n;i++)cin>>a[i];bool x=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') x=0;
	}
	if(x==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%998244353;
		}//
		cout<<ans<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
