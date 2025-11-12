#include <bits/stdc++.h>
using namespace std;
int n,a[5001],vis[5001],ans=0;
void dfs(int sum,int maxa,int l){
	if(sum>maxa*2){
		ans++;
	}
	for(int i=l;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(sum+a[i],max(maxa,a[i]),i+1);
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
	dfs(0,0,1);
	cout<<ans;
	return 0;
} 
