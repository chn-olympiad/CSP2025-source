#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
bool vis[5005];
int cnt;
int n;
bool check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			tmp++;
		}
	}
	if(tmp<3){
		return false;
	}
	int sum=0,mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
	}
	if(sum>mx*2){
		return true;
	}
	return false;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			cnt++;
		}
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else{
		dfs(1);
		cout<<cnt%mod;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
