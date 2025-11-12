#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
void dfs(int c,int maxn,int h,int cnt){
	if(maxn*2<h&&cnt>=3){
		ans++;
	}
	for(int i=c+1;i<=n;i++){
		if(a[i]>maxn)dfs(i,a[i],h+a[i],cnt+1);
		else dfs(i,maxn,h+a[i],cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}