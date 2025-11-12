#include<iostream>
#include<cstdio>
using namespace std;
int n,nn,m;
int a[505],b[505];
bool vis[505];
long long ans;
void dfs(int sum){
	if(sum>=m){
		ans++;
	}
	for(int i=1;i<=nn;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(sum+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	nn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0) nn--;
	}
	dfs(0);
	cout<<ans%998244353;
	return 0;
}
