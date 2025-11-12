#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int x,int ss,int sum,int mx){
	if(x==n+1){
		if(ss<3)return;
		if(sum>mx*2){
			ans++;
		}
		return;
	}
	dfs(x+1,ss+1,sum+a[x],max(mx,a[x]));
	dfs(x+1,ss,sum,mx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
