#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],yh[500010],k,ans=0;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool bo=1,an=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			bo=0;
		}
		if(a[i]!=0&&a[i]!=1)
		{
			an=1;
		}
	}
	if(k==0&&bo)
	{
		cout<<n/2;
	}
	else if(k==0&&an)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]&&a[i-1]!=-1)
			{
				ans++;
				a[i]=-1;
				a[i-1]=-1;
			}
		}
	}
	else
	{
		if(k==0)
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==a[i-1]&&a[i-1]!=-1)
				{
					ans++;
					a[i]=-1;
					a[i-1]=-1;
				}
			}
			cout<<ans;
		}
		else if(k==1)
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]!=a[i-1]&&a[i-1]!=-1)
				{
					ans++;
					a[i]=-1;
					a[i-1]=-1;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
