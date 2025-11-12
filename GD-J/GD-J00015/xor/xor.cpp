#include<bits/stdc++.h>
using namespace std;
long long s[200001],a[200001],q[200001],n,k,ans[200001],dp[200001],x[200001],z;
bool vis[200001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld",&n,&k);
	scanf("%lld",&a[1]);	
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=(s[i-1]^a[i]);
		if(a[i]==k) 
		{
			vis[a[i]]=1;
			z++; 
		}		
	}
	for(int i=1;i<=n;i++)
	{
		int mini=0,minj=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==k)
			{
				break;
			 } 
			if(s[i-1]^s[j]==k)
			{
				mini=i;
				minj=j;
				break;
			} 
		}
		if(mini!=0&&minj!=0)
		{
			if(x[minj]!=0) 
			{
				x[x[minj]]=0;
				vis[x[minj]]=0;
			}
			if(x[mini]!=0) 
			{
				x[x[mini]]=0;
				vis[x[mini]]=0;
			}
			vis[mini]=1;vis[minj]=1;
			x[mini]=minj;x[minj]=mini;
		}
	}
	int qqq=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(x[i]!=0)
		{
//			cout<<++qqq<<endl;
			dp[i]=max(dp[x[i]-1]+1,dp[i]);
		} 
	}
	cout<<dp[n]+z;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
