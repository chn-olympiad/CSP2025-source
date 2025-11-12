#include <iostream>
using namespace std;
int c[505],vis[505];
long long ans=0;
int n,m;
void dfs(int k,int op,int po){
	if(k>=n){
		if(op>=m){
			ans=(ans+10)%998244353;
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]>po){
				dfs(k+1,op+1,po);
			}else{
				dfs(k+1,op,po+1);
			}
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
