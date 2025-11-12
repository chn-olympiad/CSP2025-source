#include<bits/stdc++.h>

using namespace std;
char c[505];int x[505];int n,m,ans=0;
void dfs(int idx,int z,int s){
	if(idx>n){
		if(z>=m){
			ans++;
		}
		ans%=998244353;
		return;
	}
	if(idx==n&&s<x[idx]){
		if(c[idx]=='1'){
		dfs(idx+1,z,s+1);
		
		}
	else dfs(idx+1,z+1,s);
	}
	if(s>=x[idx]||c[idx]=='1'){
		dfs(idx+1,z,s+1);
	}
	else dfs(idx+1,z+1,s);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
