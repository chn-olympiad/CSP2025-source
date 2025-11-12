#include<bits/stdc++.h>
using namespace std;
int t,m[100010][4],ans,n,aa[100010];
bool af=1,bf=1;
void dfs(int now,int a,int b,int c,int sum){
	if(a>n/2||b>n/2||c>n/2) return;
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	dfs(now+1,a+1,b,c,sum+m[now][1]);
	dfs(now+1,a,b+1,c,sum+m[now][2]);
	dfs(now+1,a,b,c+1,sum+m[now][3]);
}
void dfs_bf(int now,int a,int b,int sum){
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(!(a+1>n/2)) dfs_bf(now+1,a+1,b,sum+m[now][1]);
	if(!(b+1>n/2)) dfs_bf(now+1,a,b+1,sum+m[now][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i][1]>>m[i][2]>>m[i][3];
			if(m[i][3]!=0) bf=0;
			if(m[i][3]!=0||m[i][2]!=0) af=0;
		}
		if(af){
			for(int i=1;i<=n;i++) aa[i]=m[i][1];
			sort(aa+1,aa+n+1);
			for(int i=n;i>=n/2;i--) ans+=aa[i];
			cout<<ans<<"\n";
			continue;
		}
		if(bf){
			dfs_bf(1,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
