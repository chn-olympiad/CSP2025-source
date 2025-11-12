#include<bits/stdc++.h>
using namespace std;
int n,cnt,sum,maxx,a[5005];
bool f[5005];
void dfs(int k,int sum,int l)
{
	if(k>n)
	{
		if(sum>l*2)
		{
			cnt++;
		}
		return;
	}
	if(k>=4&&sum>l*2)
	{
		cnt++;
	}
	for(int j=1;j<=n;j++)
	{
		if(a[j]<l&&f[j]==false)
		{
			f[j]=true;
			dfs(k+1,sum+a[j],l);
			f[j]=false;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3)
	{
		if(sum>maxx*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,false,sizeof(f));
		f[i]=true;
		dfs(2,a[i],a[i]);
	}
	cout<<cnt;
	return 0;
}