#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=1e6,mod=998244353;
int n,a[BIG],ans;
void dfs(int s,int l,int ma)
{
	if(s>n)
	{
		if(l>2*ma)ans++;
		ans%=mod;
		return;
	}
	dfs(s+1,l+a[s],max(ma,a[s]));
	dfs(s+1,l,ma);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
