#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
vector<int> dp[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[2].push_back(a[1]);
	dp[2].push_back(a[2]);
	dp[2].push_back(a[1]+a[2]);
	int len;
	for(int i=3; i<=n; i++)
	{
		len=dp[i-1].size();
		for(int j=0; j<len; j++)
		{
			dp[i].push_back(dp[i-1][j]);
			dp[i].push_back(dp[i-1][j]+a[i]);
			if(dp[i-1][j]>a[i]) ans++;
			//if(dp[i-1][j]>2*a[i]) ans++;
		}
		dp[i].push_back(a[i]);
	}
	/*
	for(int i=1; i<=n; i++)
	{
		len=dp[i].size();
		for(int j=0; j<len; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	cout<<ans;
	
	return 0;
} 
