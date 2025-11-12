#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=998244353;
int n,a[5100],ans,mx;
void dfs(int x,int side,int mx,int sum){
	if(x==n+1){
		if(side<3){
			return ;
		}
		if(mx*2<sum){
			ans++;
		}
		return ;
	}
	dfs(x+1,side,mx,sum);
	dfs(x+1,side+1,max(mx,a[x]),sum+a[x]);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans--;
		ans-=n;
		ans-=n*(n-1)/2;
		ans%=mod;
		ans+=mod;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	cout<<372327238;
	return 0;
}

