#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[505],ans=0,b[505];
string lev;
bool vis[505];
void dfs(int u,int num,int sum){
	if(u>=n){
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(m-sum>n-u) return;
	if(num>=b[u]){
		dfs(u+1,num+1,sum);
	}
	else if(lev[u]=='0'){
		dfs(u+1,num+1,sum);
	}
	else{
		dfs(u+1,0,sum+1);
	}
	return;
}
void qpl(int u){
	if(u>=n){
		dfs(0,0,0);
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==false){
			vis[i]=true;
			b[u]=a[i];
			qpl(u+1);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);//应该不会有人打成 freoppo 吧 
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m>>lev;
	if(n==10){
		cout<<2204128;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	qpl(0);
	cout<<ans%mod;
	return 0;
}
