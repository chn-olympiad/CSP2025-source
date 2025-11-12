#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,ok=3;
void dfs(int sum,int be,int num,int shu){
	if(num==ok&&sum>shu*2){
		ans++;
		return;
	}
	for(int i=be;i<n;i++){
		dfs(sum+a[i],i+1,num+1,a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	while(ok<=n){
		dfs(0,0,0,0);
		ok++;
	}
	cout<<ans%998244353;
	return 0;
}
