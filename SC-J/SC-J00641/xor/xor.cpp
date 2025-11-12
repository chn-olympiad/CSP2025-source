#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<(12^9);
	int n,k,a[500005],sum[500005],ans = 0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		sum[i] = (sum[i-1]^a[i]);
	}
	if(k == 0)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i] == 0)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k == 1)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i] == 1)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}