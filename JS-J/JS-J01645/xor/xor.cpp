#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans=0;
bool f=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=true;
		}
	}
	if(f==false)
	{
		cout<<n/2;
	}
	else
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				else if(a[i]==1&&a[i+1]==1)
				{
					ans++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
