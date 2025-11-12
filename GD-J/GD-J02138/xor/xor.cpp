#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010];
//int dp[500010];//1-i范围内符合题意区间数量最大值 
void dfs(int l,int r,int num)
{
	//if(l>n||r>n)return num;
	int sum=a[l];
	for(int i=l+1;i<=r;i++)
	{
		sum=sum^a[i];
	}
	//cout<<sum;
	if(sum==k)
	{
		ans++;
		if(l+1>n||r+1>n)return/* num+1*/;
		else
		{
			if(l!=r)dfs(r,r+1,num+1);
			if(l==r)dfs(r+1,r+1,num+1);
		}
	}
	else 
	{
		if(l+1>n)return /*num*/;
		else if(l!=r&&r+1>n)dfs(l+1,r,num);
		else dfs(l,r+1,num);
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(k==0&&cnt==n)
	{
		ans=n-1;
		cout<<ans;
		return 0;
	}
	/*for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		for(int j=i;j<=n;i++)
		{
			for(int h=i;h<=j;h++)
			{
				sum=sum^a[h];
				if(sum==k)
				{
					dp[i][h]=max(dp[i][h]+,)
				}
			}
			
			
		}
	}*/
	/*ans=*/dfs(1,1,0);
	cout<<ans;//<<endl
	return 0;
}
