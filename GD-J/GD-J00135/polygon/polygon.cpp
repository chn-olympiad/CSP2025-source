#include<bits/stdc++.h>
using namespace std;
bool vis[10010];
int a[10010],k[10010];
int n;
int anss = 0;
int sumup(int m){
	int ans = 0;
	for(int i = 1;i <= m;i ++){
		ans += k[i];
	}
	return ans;
}
int maxx(int m){
	int ans = -917813;
	for(int i = 1;i <= m;i ++){
		ans = max(ans,k[i]);
	}
	return ans;
}
void dfs(int u,int m,int last){
	if(u == m + 1) {
		if(sumup(m) > 2*maxx(m)) {
			anss ++;
		}
		
	}
	for(int i = last+1;i <= n;i ++){
		if(vis[i] == 0){
			vis[i] = 1;
			k[u] = a[i];
			dfs(u + 1,m,i);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i ++){
		dfs(1,i,0);
	}
	cout<<anss % 998244353;
	return 0;
}
