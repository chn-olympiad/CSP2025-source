#include<bits/stdc++.h>
using namespace std;
int n,m,sx=998244353,c=0,r[505],l=0;
long long ans=0,ans1=1;
string a;
bool p[505]={false};
void dfs(int t)
{
	if(t==n)
	{
		if(l>=m)ans++;
		return;	
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==false)
		{
			p[i]=true;
			if(r[i]<=c||a[t]=='0')
			{
				c++;
				dfs(t+1);
				c--;
			}
			else
			{
				l++;
				dfs(t+1);
				l--;
			}
			p[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	if(n==m)
	{
		for(int i=1;i<=a.size();i++)
		{
			if(a[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=m;i>1;i--)
		{
			ans*=m;
			ans%=sx;
		}
		cout<<ans;
	}
	else if(m==1)
	{
		int pos=0;
		for(int i=0;i<=a.size();i++)
		{
			if(a[i]=='1')
			{
				pos=i-1;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(r[i]>pos)ans++;
		}
		for(int i=n-1;i>1;i++)
		{
			ans*=i;
			ans%=sx;
		}
	}
	else 
	{
		int g=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='1')g++;
		}
		if(g<m)
		{
			cout<<0;
			return 0;
		}
		dfs(0);
		cout<<ans;
	}
	return 0;
}