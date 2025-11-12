#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int n;
int a[N];
int vis[N];
long long ans;
void dfs(int u,int maxx,int len){
	if(u>=3){
		if(len>2*maxx){
			ans=(ans+1)%998244353;
		}
	}
	if(u>=n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=false;
			dfs(u+1,max(maxx,a[i]),len+a[i]);
			vis[i]=true;
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
	dfs(1,a[1],a[1]);
	cout<<ans;
	return 0;
}