#include<bits/stdc++.h>
using namespace std;
int n;
int a[60010];
long long ans;
void dfs(int k,int x,int s,int sum,int maxx){
	if(s==k){
		if(sum>maxx*2) ans++;
//		cout<<sum<<" "<<maxx<<endl;
		ans%=998244353;
		return ;
	}
	for(int i=x+1;i<=n-k+s+1;i++){
		dfs(k,i,s+1,sum+a[i],max(maxx,a[i]));
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
		dfs(k,0,0,0,-1);
	}
	cout<<ans;
	return 0;
}
/*
5
2 2 3 8 10
*/
