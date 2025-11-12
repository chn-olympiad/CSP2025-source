#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
void dfs(int he,int cnt,int maxn){
	if(he>maxn*2){
		ans++;
	}
	if(he<=maxn*2){
		return;
	}
	if(cnt>n){
		return;
	}
	cout<<a[cnt]<<endl;
	int maxn1=max(maxn,a[cnt]);
	dfs(he+a[cnt],cnt++,maxn1);
	dfs(he,cnt++,maxn);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,-1);
	cout<<ans;
	return 0;
}
