#include<bits/stdc++.h>
using namespace std;
int n,a[6000],x,ans;
void dfs(int sum,int x){
	if(sum>2*x){
		ans++;
		return; 
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		x=max(a[i],x);
		dfs(sum,x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans%998244353;
	return 0;
}
