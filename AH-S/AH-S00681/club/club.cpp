#include<bits/stdc++.h>
using namespace std;
int t,n,x[100005],y[100005],z[100005],maxn=-0x3f3f3f3f;

void dfs(int a,int b,int c,int now,int ans){
	//
	
	if(a>n/2||b>n/2||c>n/2)
		return ;
	if(now>n){
		maxn=max(maxn,ans);
		return ;
	}
	//
	dfs(a+1,b,c,now+1,ans+x[now]);
	
	dfs(a,b+1,c,now+1,ans+y[now]);
	
	dfs(a,b,c+1,now+1,ans+z[now]);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=-0x3f3f3f3f;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		dfs(0,0,0,1,0);
		cout<<maxn<<endl;
	}
	return 0;
}
