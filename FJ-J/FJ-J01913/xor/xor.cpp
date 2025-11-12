#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1008611];
bool k[1008611];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,kk,ans=0;
	bool z=false;
	cin>>n>>kk;
	for(int u=1;u<=n;u++)
	{
		cin>>a[u];
		if(a[u]==0)
		z=true;
	}
	if(z==false&&kk==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	else if(kk==1)
	{
		for(int u=1;u<=n;u++)
		{
			if(a[u]==1)
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(kk==0)
	{
		for(int u=1;u<=n;u++)
		{
			if(a[u]==0)
			ans++;
			else if(a[u]==1&&k[u]==false)
			{
				if(a[u+1]==1)
				{
					k[u]=true,k[u+1]=true;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		for(int u=1;u<=n;u++)
		if(a[u]==kk)
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
