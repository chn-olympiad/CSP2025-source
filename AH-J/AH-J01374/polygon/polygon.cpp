#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5005];
bool vis[5005];
void dfs(int sum,int maxn,int x){
	if(sum>2*maxn){
		ans++;
	}
	if(vis[n]) return;
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(sum+a[i],max(a[i],maxn),i);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans%998244353<<endl;
	return 0;
}
