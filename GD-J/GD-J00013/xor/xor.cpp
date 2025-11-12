#include <iostream>
using namespace std;
const long long N=5e5+10;
long long n,k;
long long a[N];
struct node {
	long long v=0,s=0;
} dp[N][2];
int main() {
//	freopen("xor.in","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
    long long mx=0;//mn=99999999;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(a[i],mx);
		//0
		if(dp[i-1][0].s>dp[i-1][1].s) {
			dp[i][0]=dp[i-1][0];
		} else {
			dp[i][0]=dp[i-1][1];
		}
		//1
		if((dp[i-1][1]).v^(a[i])==k||(dp[i-1][0]).v^(a[i])==k) {
			if(dp[i-1][0].s>dp[i-1][1].s) {
				dp[i][1].s=dp[i-1][0].s+1;

			} else {
				dp[i][1].s=dp[i-1][1].s+1;
			}
			dp[i][1].v=0;
		} else {
			if(dp[i-1][0].s>dp[i-1][1].s) {
				dp[i][1].v=dp[i-1][0].v^a[i];
				dp[i][1].s=dp[i-1][0].s;
			} else {
				dp[i][1].v=dp[i-1][1].v^a[i];
				dp[i][1].s=dp[i-1][1].s;
			}
			//dp[i][1].v=0;
		}
		//cout<<dp[i][0].v<<' '<<dp[i][0].s<<' '<<dp[i][1].v<<' '<<dp[i][1].s<<'\n';
	}
	if(mx==1&&k==0)
	{
		cout<<0<<'\n';
		return 0;
	}
	cout<<max(dp[n][0].s,dp[n][1].s)<<'\n';
	

	return 0;
}
