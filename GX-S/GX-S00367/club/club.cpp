#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,t,m,a[maxn][4],ans;
void dfs(int id,int m1,int m2,int m3,int res){
	if(m1>m||m2>m||m3>m)return;
	if(id==n-1){
		if(res+max(a[id+1][1],max(a[id+1][2],a[id+1][3]))<=ans)return;
	}
	if(id==n){
		ans=max(res,ans);
		return;
	}
	dfs(id+1,m1+1,m2,m3,res+a[id+1][1]);
	dfs(id+1,m1,m2+1,m3,res+a[id+1][2]);
	dfs(id+1,m1,m2,m3+1,res+a[id+1][3]);
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
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
