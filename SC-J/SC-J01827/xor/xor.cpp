#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
int dp[maxn],a[maxn];
unordered_map<int,int> mp;
int f(int x,int y)
{
	int ans=x^y;
	if(mp.find(ans)==mp.end()) return -1;
	return mp[ans];
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		int now=f(a[i],k);
		if(now!=-1) dp[i]=max(dp[i],dp[now]+1);
		mp[a[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
