#include<iostream>
#include<cstdio>
#include<stack>
#define var long long
using namespace std;
var a[5001],n,ans;
int dfs(var p,var sum,var maxs){
	if(p>n){
		if(maxs*2<sum){
			ans++;
			ans%= 998244353 ;
		}
		return 0;
	}
	dfs(p+1,sum+a[p],max(maxs,a[p]));
	dfs(p+1,sum,maxs);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(var i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
