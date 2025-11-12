#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll IF=998244353;
ll n,a[10007],dp[10007],dis[50007],sum,sur[50007],del_1[507][507],ans;
void dfs(ll maxn,ll ste,ll sum,ll kss){
	if(ste==n+1){
		if(maxn*2<sum&&kss>=3) ans++;
		return;
	}
	dfs(max(maxn,a[ste]),ste+1,sum+a[ste],kss+1);
	dfs(maxn,ste+1,sum,kss);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	del_1[1][1]=1;
	for(int i=2;i<=500;i++){
		for(int j=1;j<=i;j++){
			del_1[i][j]=(del_1[i-1][j]+del_1[i-1][j-1])%IF;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n){
		for(int i=3;i<=n;i++){
			ans=(ans+del_1[n+1][i+1])%IF;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}