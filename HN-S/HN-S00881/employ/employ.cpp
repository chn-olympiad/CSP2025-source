#include<bits/stdc++.h>
using namespace std;
char a[505];
int c[505];
int n,m;
int main()
{
	int p=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='1')
		{
			p++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(p<m)
	{
		cout<<0;
		return 0;
	}
	if(n==m&&n==p)
	{
		int ans=1;
		for(int i=n;i>=1;i--)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
