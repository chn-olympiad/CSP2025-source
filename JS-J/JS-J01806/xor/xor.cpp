#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool flag_A=true,flag_B=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag_A=false;
		if(a[i]>1) flag_B=false;
	}
	if(flag_A)
	{
		cout<<n/2;
		return 0;
	}
	if(flag_B)
	{
		if(k)
		{
			for(int i=1;i<=n;i++)
				if(a[i])
					ans++;
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(!a[i])
					ans++;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]) sum++;
				else
				{
					ans=ans+sum/2;
					sum=0;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]>=k)
			ans++;
	cout<<ans<<'\n';
	return 0;
}
