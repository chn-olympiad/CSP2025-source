#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=5e5+10;
const int maxm=2e6+10;
const int mod=1e9+7;
int n,k,a[maxn],S=(1<<20),lst[maxm],dp[maxn],s;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for (int i=0;i<S;i++) lst[i]=-1;
	lst[0]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		cin >> a[i];
		s^=a[i];
		if (lst[s^k]!=-1) dp[i]=max(dp[i],dp[lst[s^k]]+1);
		lst[s]=i;
	}
	cout << dp[n];
	return 0;
}
