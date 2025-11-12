#include<bits/stdc++.h>
using namespace std;
long long n,k,z[600000],x[600000],ans,dp[600000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int q=1;q<=n;q++)
	{
		cin>>z[q];
	}
	for(int q=1;q<=n;q++)
	{
		x[q]=z[q]^x[q-1];
	}
	for(int q=1;q<=n;q++)
	{
		dp[q]=dp[q-1];
		for(int w=q;w>0;w--)
		{
			if(dp[w-1]+1<dp[q]) break;
			if((x[q]^x[w-1])==k) 
			{
				dp[q]=max(dp[q],dp[w-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
 } 
