#include<bits/stdc++.h>
using namespace std;
int a[5001],b,k,ans;
void dfs(int x,int z){
	if(z==k&&x!=0){
		ans++;
	}
	for(int i=x+1;i<=b;i++){
		if(z!=a[i]){
			dfs(i,1);
		}
		else{
			dfs(i,0);
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b>>k;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;




	return 0;
}
