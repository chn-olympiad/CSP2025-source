#include "bits/stdc++.h"
using namespace std;
int n,a[100010],ans;
bool vis[100010];
void dfs(int s,int maxn,int last){
	if(s>maxn*2){
		ans++;
		cout<<s<<" "<<maxn<<endl;
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(s+a[i],max(maxn,a[i]),i);
			vis[i]=0;
		}
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int u=1,e=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>1) u=0;
		if(a[i]==1) e++;
	}
	sort(a+1,a+n+1);
	if(u==1) {
		int o=0;
		for(int i=3;i<=e;i++){
			int x=1,y=1;
			for(int j=e;j>=e-i+1;j--) x*=j;
			for(int j=1;j<=i;j++) y*=j;
			o+=x/y;
		}
		cout<<o%998244353<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%998244353<<endl;
	return 0;
}
/*
5 
1 2 3 4 5
*/
