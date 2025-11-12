#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
bool vis[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool pd=1,f=1,ff=1;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			pd=0;
		}
		if(a[i]>1)
		{
			f=1;
		}
		if(a[i]==k)
		{
			c++;
			vis[i]=1;
		}
		if(a[i]>255)
		{
			ff=0;
		}
	}
	if(ff && k>255)
	{
		cout<<0;
		return 0;
	}
	if(pd && k==0)
	{
		cout<<n/2;
		return 0;
	}
	else if(f && k<=1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) cnt++;
		}
		if(k==1)
		{
			cout<<cnt;
			return 0;
		}
		else
		{
			int x1=cnt/2;
			int x0=(n-cnt)/2;
			cout<<x0+x1;
			return 0;
		}
	}
	else
	{
		int cnt=0;
		int ans=c;
		for(int i=1;i<=n;i++)
		{
			if(cnt==0 && vis[i]==0)
			{
				cnt=a[i];
			}
			else if(vis[i]==0)
			{
				cnt^=a[i]; 
			}
			else if(vis[i]==1)
			{
				cnt=0;
			}
			if(cnt==k)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}

