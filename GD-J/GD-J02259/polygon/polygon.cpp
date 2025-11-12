#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long ans; 
void dfs(int now,int maxx,int sum,int non){
	if(non>n){
		if(n-now>=3 && n-now<=n){
			if(sum>maxx*2)ans++;
		}return ;
	}
		dfs(now-1,max(maxx,a[non]),sum+a[non],non+1);
		dfs(now,maxx,sum,non+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	dfs(n,-1e9,0,1);
	cout<<ans%(long long)998244353;
	return 0;
}
