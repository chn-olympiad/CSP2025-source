#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int n,k,a[N],sum[N],dp[N];
struct node{
	int l,r;
}b[M];
vector<int> g[N];
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	int tot=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1])==k){
				b[++tot]={l,r};
				g[r].push_back(l);
			} 
		} 
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		for(auto l:g[i])
			dp[i]=max(dp[i],dp[l-1]+1);
	} 
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,dp[i]);
	cout<<maxn;
	return 0;
}
