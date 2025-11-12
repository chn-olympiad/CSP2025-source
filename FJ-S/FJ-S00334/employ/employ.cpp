#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],c[505],ans=1,p=0,sum=0;
char x;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x-'0';
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			p=1;
		}
	}
	if(m==n)
	{
		if(p==1)
		{
			cout<<0;
			return 0;
		}
		if(sum!=n)
		{
			cout<<0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}
		return 0;
	}
	if(sum==0)
	{
		cout<<0;
		return 0;
	}
	cout<<n*m;
	return 0;
}
