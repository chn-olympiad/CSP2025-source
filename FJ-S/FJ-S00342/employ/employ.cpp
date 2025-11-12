#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,p[1000],c[1000],vis[1000];
const long long mod=998244353;
string str;
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<p[i]<<" "<<sum<<" "<<c[p[i]]<<" ";
			if(sum>=c[p[i]])
			{
				sum++;
			}
			else
			{
				if(str[i-1]=='0')
				{
					sum++;
				}
			}
		}
		if(n-sum>=m)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=100)
	{
		dfs(1);
	}
	else
	{
		ans=0;
	}
	cout<<ans;
	return 0;
}
