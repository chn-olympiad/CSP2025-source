#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans=0;
void dfs(int cnt,int big,int step,int num){
	if(cnt>big*2&&num>=3){
		ans++;
		ans=ans%998244353;
	}
	for(int i=step+1;i<=n;i++){
		dfs(cnt+a[i],max(big,a[i]),i,num+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
