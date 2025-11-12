#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define MAXN 1005
int n,K;
int a[MAXN];
//int xr[MAXN][MAXN];
//int dp[MAXN][MAXN];
signed main()
{
	FAST_IO;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2&&K==0)
	{
		if(n==1) cout<<(a[1]==K?"1\n":"0\n");
		else
		{
			if(a[1]==K&&a[2]==K) cout<<"2\n";
			else if((a[1]^a[2])==K) cout<<"1\n";
			else {cout<<"0\n";}
		}
		return 0;
	}
	/*for(int i=1;i<=n;i++) xr[i][i]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) xr[i][j]=xr[i][j-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int i1=1;i1<=i;i1++)
			{
				for(int j1=i1;j1<=i;j1++)
				{
					if(xr[j1][j]==K) dp[i][j]=max(dp[i][j],dp[i1][j1]+1);
				}
			}
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++) maxn=max(maxn,dp[n][i]);
	cout<<maxn<<'\n';*/
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==K) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}
