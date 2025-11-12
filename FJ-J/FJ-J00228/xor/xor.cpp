#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	vector<int>sz(n);
	for(int q=0;q<n;q++)
	{
		cin>>sz[q];
	}
	if(k==0)
	{
		int gs=0;
		for(int q=0;q<n;q++)
		{
			if(sz[q]==0)
			{
				ans++;
				gs=0;
			}
			else
			{
				if(sz[q]==1)
				{
					gs++;
				}
				if(q==n-1||sz[q+1]==0)
				{
					ans+=gs/2;
				}
			}
		}
	}
	else
	{
		for(int q=0;q<n;q++)
		{
			if(sz[q]==1)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
