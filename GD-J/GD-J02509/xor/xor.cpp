#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,k,ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	ll a[n+1];
	ll dp_result[n+1][n+1];
	ll dp_ans[n+1][n+1];
	memset(a,0,sizeof(a));
	memset(dp_result,0,sizeof(dp_result));
	memset(dp_ans,0,sizeof(dp_ans));

	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dp_result[i][i]=a[i];
	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dp_result[i][j]=dp_result[i][j-1] xor a[j];
	
	
	
	if(dp_result[n][n]) dp_ans[n][n]=1;
	
	for(int i=n-1;i>=1;i--)
	{
		if(dp_result[i][n]==k)
			dp_ans[i][n]++;
		dp_ans[i][n]+=dp_ans[i+1][n];
	}
			
	for(int i=n-1;i>=2;i--)
	{
		for(int j=n-1;j>=i;j--)
		{
			if(dp_result[i][j]==k) dp_ans[i][j]=1;	
			dp_ans[i][j]+=dp_ans[i-1][j]+dp_ans[i][j-1]-dp_ans[i-1][j-1];
		}
	}
	
	for(int i=1;i<=n-1;i++)
		for(int j=i;j<=n-1;j++)
			dp_ans[i][j]=(dp_result[i][j]==k? dp_ans[i-1][j-1]+1:dp_ans[i-1][j-1]);
			
	ans=dp_ans[1][1];
			
	cout<<ans<<endl<<endl;
	
	
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			cout<<dp_result[i][j]<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			cout<<dp_ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
//4 3
//2 1 0 3
