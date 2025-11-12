#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n,k,a[500005],s[500005],mx[2100005],dp[500005];
signed main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]^a[i];
	memset(mx,-1,sizeof(mx));
	for (int i=1;i<=n;i++)
	{
		dp[i]=max(mx[k^s[i]]+1,dp[i-1]);
		mx[s[i]]=max(mx[s[i]],dp[i]);
	}
	cout << dp[n];
	return 0;
}
