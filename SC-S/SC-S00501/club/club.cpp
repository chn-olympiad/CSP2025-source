#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,A[100005][4],dp[105][105][105],X[100005];
int dfs(int id,int a,int b,int c) {
	if(id>n) {
		return 0;
	}
	if(dp[a][b][c]) {
		return dp[a][b][c];
	}
	int ans=0;
	if(a<(n/2)) {
		ans=max(ans,A[id][1]+dfs(id+1,a+1,b,c));
	}
	if(b<(n/2)) {
		ans=max(ans,A[id][2]+dfs(id+1,a,b+1,c));
	}
	if(c<(n/2)) {
		ans=max(ans,A[id][3]+dfs(id+1,a,b,c+1));
	}
	return dp[a][b][c]=ans;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<=200) {
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=n; i++) {
				cin>>A[i][1]>>A[i][2]>>A[i][3];
			}
			cout<<dfs(1,0,0,0)<<"\n";
		} else {
			for(int i=1; i<=n; i++) {
				cin>>X[i]>>X[0]>>X[0];
			}
			sort(X+1,X+n+1);
			int ans=0;
			for(int i=(n/2)+1;i<=n;i++){
				ans+=X[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
