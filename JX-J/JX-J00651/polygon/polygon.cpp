#include <bits/stdc++.h>
using namespace std;
int n;
int mod=998244353;
int a[5010];
long long ans=0;
bool vis[5010];
void dfs(int k,int maxx,int sum){
	if(k==n){
		return ;
	}
	if(k>=3 && sum>maxx*2){
		ans++;
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			maxx=max(maxx,a[i]);
			vis[i]=1;
			sum+=a[i];
			dfs(k+1,maxx,sum);
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
}
	dfs(0,0,0);
	cout<<ans;
return 0;
}

