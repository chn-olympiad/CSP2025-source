#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[505];
int b[505],ee=0,a1[1005],b1[5000],ans;
void eee(int e)
{
	if(e==n)
	{
		for(int i=1;i<=n;i++)
		{
			b1[a1[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(b1[i]==0)
			return;
		}
		int e111=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0')
			e111++;
			if(e111>b[b1[i]])
			{
				e111++;
			}
		}
		if(n-e111>=m)
		ans++;
	}
	for(int i=1;i<=n;i++)
	{
		a1[e]=i;
		eee(e+1);
		a1[e]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ee+=a[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(ee==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=n;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<eee(0);
}
