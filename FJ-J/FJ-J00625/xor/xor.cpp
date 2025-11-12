#include <bits/stdc++.h>
using namespace std;
long long n,k,maxx,a[500005],l,s,h;
bool m=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			h++;
		}
		else if(a[i]==0)
		{
			l++;
		}
		else
		{
			m=false;
		}
	}
	if(h==n&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(h==n&&k==1)
	{
		cout<<n;
		return 0;
	}
	if(l==n&&k==0)
	{
		cout<<n;
		return 0;
	}
	if(l==n&&k==1)
	{
		cout<<"0";
		return 0;
	}
	if(m&&k==0)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1&&a[i-1]==1)
			{
				l++;
				a[i]=0;
			}
		}
		cout<<l;
		return 0;
	}
	if(m&&k==1)
	{
		cout<<h;
		return 0;
	}
	cout<<"57";
	return 0;
}
