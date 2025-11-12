#include<bits/stdc++.h>
using namespace std;
long long n,a[5003],ans=0,vis[5003],p[5003];
void dfs(long long h,long long id,long long maxn){
	if(id>n+1) return;
	
	if(id>=3&&h>maxn*2){
		ans++;
		ans=ans%998244353;
	}
	for(int i=id;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(h+a[i],i+1,max(maxn,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}