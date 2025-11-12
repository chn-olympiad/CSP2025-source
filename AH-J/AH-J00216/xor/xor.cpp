#include <bits/stdc++.h>
using namespace std;

int dp[500005];
int a[500005];
int s[500005];
int rp[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	rp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if ((s[i]^k)==0||rp[s[i]^k]>0) dp[i]=max(dp[i],dp[rp[s[i]^k]]+1);
		rp[s[i]]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
