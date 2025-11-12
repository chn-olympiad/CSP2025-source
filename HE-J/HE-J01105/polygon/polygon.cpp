#include<bits/stdc++.h>
using namespace std;
int n,a[50001],ans,mark[50001];
int dfs(int y,int x,int step,int _max,int cnt){
	if(step==y){
		if(2*_max<cnt){
			ans=ans+1;
			ans=ans%998%244%353;
		}
		return 0;
	}
	for(int i=x;i<=n;i++){
		dfs(y,i+1,step+1,max(_max,a[i]),cnt+a[i]);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(i,j+1,1,a[j],a[j]);
		}
	}
	cout<<ans;
	return 0;
}
