#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10001],flag=1,ans=0,vis[1001],need;
bool cmp(int x,int y){
	return x<y;
}
void dfs(int sum,int maxx,int dep,int k){
	if(dep==need){
		if(sum>maxx*2){
			ans%=998244353;
			ans++;
		}
		return ;
	} 
	for(int i=k+1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(sum+a[i],max(maxx,a[i]),dep+1,i);
		vis[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag==1){
		cout<<n-2;
		return 0;
	}
	for(need=3;need<=n;need++){
		dfs(0,0,0,0);
	}
	cout<<ans;
	return 0;
}
