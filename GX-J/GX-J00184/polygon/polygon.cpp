#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int vis[5010],n,a[5050],ans;
void dfs(int k,int c,int sum,int maxx){
	if(k>n){
		if(sum>maxx*2&&c>=3)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=k;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,c+1,sum+a[i],max(maxx,a[i]));
			dfs(k+1,c,sum,maxx);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
