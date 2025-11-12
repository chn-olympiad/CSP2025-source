#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool c=true;
	bool d=true;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			c=false;
		}
		if(a[i]!=1&&a[i]!=0)
		{
			d=false;
		}
	}
	
	if(c)
	{
		cout<<n/2;
		return 0;
	}
	if(d)
	{
		if(k==0)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}else if(a[i]==1&&a[i+1]==1)
				{
					i++;
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}else if(k==1)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
