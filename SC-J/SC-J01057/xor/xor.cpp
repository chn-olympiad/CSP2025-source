#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,t,a[500005],p[500005],dp[500005],n,m,ans;
unordered_map<int,vector<int>> ve;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ve[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
//		cout<<signed(p[i]^k)<<" ";
		ve[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int x=p[i]^k;
		if(ve[x].empty()||ve[x].front()>=i){
			dp[i]=dp[i-1];continue;
		}
		int u=lower_bound(ve[x].begin(),ve[x].end(),i)-ve[x].begin();
		u=ve[x][u-1];
		if(u>=t&&dp[u]+1>dp[i-1]){
			dp[i]=dp[u]+1,t=i;
		}else{
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/