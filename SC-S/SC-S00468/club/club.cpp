#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],ans;
void dfs(int dep,int tot1,int tot2,int tot3,int sum){
	if(dep==n+1){
		ans=max(ans,sum);
		return;
	}
	if(tot1!=n/2) dfs(dep+1,tot1+1,tot2,tot3,sum+a[dep][1]);
	if(tot2!=n/2) dfs(dep+1,tot1,tot2+1,tot3,sum+a[dep][2]);
	if(tot3!=n/2) dfs(dep+1,tot1,tot2,tot3+1,sum+a[dep][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}