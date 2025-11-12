#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==a[i+1]&&a[i]==1)
			{
				ans++;
				i++;
			}
		}
	}
	else if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
