#include<bits/stdc++.h>

using namespace std;

long long dp[1005][1005],n,k,a[100005],allsum=0;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int len=1;len<=n;len++)
	{
		long long ans=a[len],sum=0;
		for(int i=len+1;i<=n;i++)
		{
			if(ans==k){
				sum++,ans=a[i];	
			} 
			else {
				ans^=a[i];
			}
			
		}
		if(ans==k) sum++;
		allsum=max(allsum,sum);
	}
	cout<<allsum;
	return 0;
 } 
