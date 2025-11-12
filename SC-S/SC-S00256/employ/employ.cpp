#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],vis[505],a[505];
long long ans,cnt,mo=998244353;
string s;
void dfs(int x){
	if(x>=n){
		ans=(ans+1)%mo;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=c[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1);
		vis[i]=0;
	}
	cout<<ans;
}