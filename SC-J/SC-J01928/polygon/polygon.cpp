#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[100006],dp[5006][5006];
bool cmp(int a,int b)
{
	return a>b;
}
int P[100006]; 
void init()
{
	P[0]=1; 
	for(int i=1;i<=n+5;i++)
	{
		P[i]=P[i-1]*2%mod;
	}
}
int maxa;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	maxa=a[1];
	init();
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=maxa+5;j++)
		{
			if(a[i]>=j)dp[i][j]=dp[i+1][j]+P[n-i];
			else dp[i][j]=dp[i+1][j]+dp[i+1][j-a[i]];
			
			dp[i][j]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dp[i+1][a[i]+1];
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 