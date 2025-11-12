#include<bits/stdc++.h>
using namespace std;
//#define int long long <------------------------
int n;
int a[5001];
int dp[5000010];
int ans;
int maxx;
const int mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx+=a[i];
	}
	sort(a+1,a+1+n);
	maxx=min(maxx,50000);
	for(int i=1;i<=n;i++)
	{
		for(int j=maxx+1;j>=1;j--)
		{
			if(!dp[j]) continue;
			int q=j+a[i];
			if(q>maxx) q=maxx+1;
			dp[q]=(dp[q]%mod+dp[j]%mod)%mod;
			if(q>2*a[i]) ans=(ans%mod+dp[j]%mod)%mod;
		}
		dp[a[i]]=(dp[a[i]]+1)%mod;
		
	}
	cout<<ans%mod;
	return 0;
}
/*

shen shou bao you

*/
