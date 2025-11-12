#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10005],ans=0,vis[10005],c[10005];
bool check(int x,int y){
	if(x>y*2){
		return true;
	}
	return false;
}
void dfs(int x,int m){
	if(x==m+1){
		int sum=0,maxn=-1;
		for(int i=1;i<=m;i++){
			sum+=a[c[i]];
			maxn=max(maxn,a[i]);
		}
		if(check(sum,maxn)){
			ans++;
		}
		return;
	}
	for(int i=x;i<=m;i++){
		if(vis[i]==0){
			c[x]=i;
			vis[i]=1;
			dfs(x+1,m);
			vis[i]=0;
			c[x]-=i;
		}
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	return 0;
}

