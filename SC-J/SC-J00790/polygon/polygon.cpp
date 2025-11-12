#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","t",stdout);
	int n,a[10000],w[10000],dp[1000][1000];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=a[i];j<=2*a[i];j++)
		{
			dp[i][j]+=dp[i][j-1];
				if(j>=a[i])
				{
					dp[i][j]+=dp[i-1][j-a[i]];
				}
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
		ans+=w[i]-dp[i][2*a[i]];
		cout<<ans;
		}
	

	return 0;
}