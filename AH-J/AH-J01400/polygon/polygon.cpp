#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],vis[5005];
ll ans;
void dfs(ll len,int cnt,int maxl,int num,int p){
	if(cnt==num){
		if(len>2*maxl){
			ans++;
		}
		return;
	}
	for(int i=p;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(len+a[i],cnt+1,max(maxl,a[i]),num,i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(0,0,0,i,1);
	}
	cout<<ans%998244353;
	return 0;
}
