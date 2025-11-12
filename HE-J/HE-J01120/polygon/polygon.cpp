#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int i,int sum,int mx,int m){
	if(i==n){
		if(mx*2<sum && m>=3){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(i+1,sum+a[i+1],max(mx,a[i+1]),m+1);
	dfs(i+1,sum,mx,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
