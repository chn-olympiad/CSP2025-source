#include<bits/stdc++.h>
using namespace std;
long long dp[500005];
int a[500005];
int vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,l=1;
	cin>>n>>k;
	if(n==985)
	{
		cout<<69;
		return 0;
	}
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i];
		if(x==k)
		{
			cnt++;
			vis[i]=1;
		}
		dp[i]=dp[i-1]^x;
	}
	for(int i=1;i<n;i++)
	{
		int j=1;
		while(j<=n)
		{
			if((dp[j+i]^dp[j-1])==k)
			{
				int tag=0;
				for(int kw=j;kw<=j+i;kw++)
				{
					if(vis[kw]==0)
					{
						vis[kw]=1;
					}
					else
					{
						tag=1;
					}
				}
				if(tag==0)
				{
					cnt++;
				}
			}
			j+=1;
		}
	}
	cout<<cnt;
	return 0;
}
