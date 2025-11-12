#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n, m, s[510], c[510], cnt, vis[510], ans, a[510];
bool check(){
    int cnt=0, tot=0;
	for(int i=1; i<=n; i++){
		if(cnt>=a[i]){
			cnt++;
		}
		else if(s[i]==0){
			cnt++;
		}
		else{
			tot++;
		}
	}
	return tot>=m;
}
void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
			ans=ans%MOD; 
		}
		return ;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			vis[i]=1;
			a[i]=c[x];
			dfs(x+1);
			vis[i]=0;
		} 
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		char c;
		cin>>c;
		if(c=='1'){
			s[i]=1;
		}
		else{
			s[i]=0;
		}
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
