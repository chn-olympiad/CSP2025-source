#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int ans=0;
int vis[5005];
void dfs(int ge,int x,int sum,int maxx,int fa){
	if(x==ge+1){
		if(sum>maxx*2){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&a[i]>=fa){
			vis[i]=1;
			dfs(ge,x+1,sum+a[i],max(maxx,a[i]),a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0);
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}