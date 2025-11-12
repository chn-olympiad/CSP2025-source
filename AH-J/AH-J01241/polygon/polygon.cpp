#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,a[5010],maxn=0;
void dfs(int i,int b,int he,int maxn){
	if(i==b){
		if(he>maxn*2){
			ans++;
		}
		return;
	}
	dfs(i+1,b,he+=a[i],max(maxn,a[i]));
	dfs(i+1,b,he,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		int he=0;
		for(int i=1;i<=n;i++){
			he+=a[i];
		}
		if(he>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=3;i<=n;i++){
			dfs(1,i,0,0);
		}
		cout<<ans;
	}
	return 0;
}
