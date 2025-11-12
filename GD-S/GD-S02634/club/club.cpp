#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
const int N=1e5+10;
int a[N][4],ans=-1;
int v[N];
void dfs(int x,int v1,int v2,int v3,int op){
	if(v1>n/2||v2>n/2||v3>n/2) return;
	if(x==n){
		ans=max(ans,op);return;
	}
	dfs(x+1,v1+1,v2,v3,op+a[x+1][1]);
	dfs(x+1,v1,v2+1,v3,op+a[x+1][2]);
	dfs(x+1,v1,v2,v3+1,op+a[x+1][3]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1;
		bool fla=0,flb=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0) fla=1;
			if(a[i][3]!=0) flb=1;
		}
		if(n<=30){
			dfs(1,1,0,0,a[1][1]);
			dfs(1,0,1,0,a[1][2]);
			dfs(1,0,0,1,a[1][3]);
			cout<<ans<<"\n";
			continue;
		}
		if(!fla&&!flb){
			for(int i=1;i<=n;i++) v[i]=a[i][1];
			sort(v+1,v+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i--) ans+=v[i];
			cout<<ans<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4);
			ans+=a[i][3];		
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
2
10 9 8
4 0 0
*/
