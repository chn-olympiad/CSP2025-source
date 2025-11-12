#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,k,sum[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		//cout<<sum[i]<<" ";
	}
	int ans=0,l=1,r=1;
	while(l<=r&&r<=n)
	{
		for(int i=l; i<=r; i++)
		{
			if((sum[r]^sum[i-1])==k||(sum[r]^sum[r-1])==k)
			{
				ans++;
				l=r;
				l++;
				break;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
} 
