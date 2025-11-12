#include<bits/stdc++.h>

using namespace std;

int a[500010];

int main()
{

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int i;
	bool b=true;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>k)
		{
			b=false;
		}
	}
	if(b==true)
	{
		cout<<0<<endl;
		return 0;
	}
	int ans=0;
	if(k==1)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else
			{
				if(a[i+1]!=0)
				{
					ans++;
					i++;
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
