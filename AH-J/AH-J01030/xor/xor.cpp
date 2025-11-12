#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,maxn;
int a[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=0;
		}
		maxn=max(maxn,a[i]);
	}
	if(f)
	{
		cout<<n/2<<"\n";
		return 0;
	}
	if(maxn<=1)
	{
		if(k==1)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		else
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					cnt++;
				}
				else
				{
					if(a[i+1]==1)
					{
						i++;
						cnt++;
					}
				}
			}
			cout<<cnt<<"\n";
		}
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0,j;
		for(j=i;j<=n;j++)
		{
			cnt^=a[j];
			if(cnt==k)
			{
				sum++;
				break;
			}
		}
		i=j;
	}
	cout<<sum<<"\n";
	return 0;
}
/*
*/
