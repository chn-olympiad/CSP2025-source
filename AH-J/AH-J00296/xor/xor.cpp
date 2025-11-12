#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],qwe,iop;
long long cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			qwe++;
		}
		if(a[i]==0)
		{
			iop++;
		}
	}
	if(qwe==n)
	{
		if(n%2==0)
		{
			cout<<n/2;
			return 0;
		}
		else if(n%2==1)
		{
			cout<<(n-1)/2;
		}
	}
	else if(iop+qwe==n)
	{
		if(k==0)
		{
			for(int i=1;i<n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					i+=2;
					cnt++;
				}
				if(a[i]==0)
				{
					cnt++;
				}
			}
		}
		else if(k==1)
		{
			for(int i=1;i<n;i++)
			{
				if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))
				{
					i+=2;
					cnt++;
				}
				if(a[i]==1)
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
}
