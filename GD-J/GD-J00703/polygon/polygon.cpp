#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e3+10;
const int mod = 998244353;

ll dp[maxn][maxn][4];
ll a[maxn];
ll pre[maxn];
ll buck[maxn];int n;
ll pre1[maxn][maxn], pre2[maxn][maxn];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}
	sort(a+1,a+1+n);
	// dp
	for(int i=1;i<=n;i++)
	{
		for(ll j=0;j<=pre[i];j++)
		{
			dp[i][j][0] = (j==a[i]?1:0);
			if(j-a[i]<=a[i] && j-a[i]>=0) dp[i][j][1] = buck[j-a[i]]%mod; // j-a[i]<=a[i] &&
			ll su = 0;
			su = (pre1[i-1][j-a[i]] + pre2[i-1][j-a[i]])%mod;
			dp[i][j][2] = su;
			//debug: cout<<"dp["<<i<<"]["<<j<<"][0/1/2]="<< dp[i][j][0]<<' '<< dp[i][j][1]<<' '<< dp[i][j][2]<<"\n";
			pre1[i][j] =(pre1[i-1][j]+dp[i][j][1])%mod;
			pre2[i][j] =(pre2[i-1][j]+dp[i][j][2])%mod;
		}
		buck[a[i]]++;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) for(ll j=0;j<=pre[i];j++)  if(j>2*a[i]) ans=(ans+dp[i][j][2])%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
