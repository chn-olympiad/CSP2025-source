#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void dfs(int k,int b,int c,int d){
	if(k>n){
		if(c>b*2&&d>=3) ans++;
		return;
	}
	dfs(k+1,b,c,d);
	dfs(k+1,max(a[k],b),c+a[k],d+1);
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}dfs(1,0,0,0);
	cout<<ans;
}