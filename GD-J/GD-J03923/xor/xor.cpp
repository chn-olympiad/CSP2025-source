#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10,maxm=11e5;
int n,k,a[maxn],b[maxn],c[maxm],dp[maxn];
void solve1(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		int t=k^b[i];
		dp[i]=dp[i-1];
		if(c[t]!=0||t==0)dp[i]=max(dp[i-1],dp[c[t]]+1);
		c[b[i]]=i;
	}
	cout<<dp[n];
}
void solve(){
	if(1)solve1();
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
