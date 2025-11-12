#include <bits/stdc++.h>
using namespace std;
long long T,n,a[100005][5],ans,cnt[5];
void dfs(int x,long long sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}