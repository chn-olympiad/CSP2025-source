#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[10010][4],ans;
void dfs(int stp,int a1,int a2,int a3,int sum){
	if(stp==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a1<n/2)dfs(stp+1,a1+1,a2,a3,sum+a[stp][1]);
	if(a2<n/2)dfs(stp+1,a1,a2+1,a3,sum+a[stp][2]);
	if(a3<n/2)dfs(stp+1,a1,a2,a3+1,sum+a[stp][3]);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=30){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}