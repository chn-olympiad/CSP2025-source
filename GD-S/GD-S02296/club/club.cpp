#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,k;
int a[100005][5],cnt[5];
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i) for(int j=1;j<=3;++j) cin>>a[i][j];
		ans=0;
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
