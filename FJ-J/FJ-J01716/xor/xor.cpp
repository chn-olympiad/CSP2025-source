#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int cnt[(1<<20)+5];
int dp[500005];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		int flc=a[i]^k;
		if(cnt[flc]||flc==0)
		dp[i]=dp[cnt[flc]]+1;
		dp[i]=max(dp[i],dp[i-1]);
		cnt[a[i]]=i;
	}
	cout<<dp[n];
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}

// AKed.
// flc AK CSP-J!
// ADBC 9:28
// CSP-S rp++.

// 4/73
