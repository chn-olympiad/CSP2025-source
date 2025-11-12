#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	vector<vector<int>> dp(n+5,vector<int>(n+5,0));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if((s[j+i-1]^s[j-1])==k)
			{
				dp[j][j+i-1]=1;
				//cout<<j<<"--"<<j+i-1<<"\n";
			} 
			for(int w=j;w<j+i-1;w++)
			{
				dp[j][i+j-1]=max(dp[j][i+j-1],dp[j][w]+dp[w+1][i+j-1]);
			}
		}
	}
	/* 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int t=s[j]^s[i-1];
			cout<<i<<"--"<<j<<":"<<t<<"\n";
		}
	}
	*/
	cout<<dp[1][n];
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
