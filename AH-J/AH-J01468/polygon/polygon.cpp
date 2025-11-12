#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
void dfs(int x,int cnt,int mx,int alllong){
	if(cnt>=3&&alllong>2*mx){
		ans++;
		ans=ans%998244353;
		if(x==n) return;
		dfs(x+1,cnt+1,max(mx,a[x]),alllong+a[x]);
		return;
	}
	if(x==n) return;
	dfs(x+1,cnt,mx,alllong);
	dfs(x+1,cnt+1,max(mx,a[x]),alllong+a[x]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
