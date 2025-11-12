#include <bits/stdc++.h>
using namespace std;

//区间dp（非正确解法） 
/*
int n,k,ans;
int a[500000];
bool no[500000];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int dp[n][n]; 
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(j==i)dp[i][j]=a[i];
			else dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			int c=j,r=i+j;
			bool ok=true;
			if(dp[c][r]==k)
			{
				for(int k=c;k<=r;k++)
				{
					if(no[k])
					{
						ok=false;
						break;
					}
				}
				if(ok)
				{
					for(int k=c;k<=r;k++)
					{
						no[k]=true;
					}
					ans++;
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
*/

//记忆化dfs   13针对得分 
 
int n,k;
int a[500000];
int f[1000][1000];
int dp[1000][1000];
int all=-1;

int dfs(int l,int r)
{
	int ans=0;
	
	if(l==r && a[l]==k)
	{
		f[l][r]=1;
		return 1;
	}
	
	if(dp[l][r]==k)ans++; 
	
	for(int i=l;i<r;i++)
	{
		int x,y;
		if(l<1000 && i<1000 && f[l][i]!=-1)x=f[l][i];
		else x=dfs(l,i);
		
		if(i+1<1000 && r<1000 && f[i+1][r]!=-1)y=f[i+1][r];
		else y=dfs(i+1,r);
		
		if(x+y>ans)ans=x+y;
	}
	f[l][r]=ans;
	return ans;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(all==-1)all=a[i];
		else if(all!=a[i])all=-2;
	}
	
	if(all==k && n>1000)
	{
		cout << n;
		return 0;
	}
	else if(all==0 && k==1 && n>1000)
	{
		cout << 0;
		return 0;
	}
	else if(all==1 && k==0 && n>1000)
	{
		cout << n/2;
		return 0;
	}
	
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			f[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(j==i)dp[i][j]=a[i];
			else dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	cout << dfs(0,n-1);
	return 0;
}
