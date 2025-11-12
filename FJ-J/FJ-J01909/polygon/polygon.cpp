#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100000],ans,vis[100000];
void dfs(ll x,ll cnt,ll mx,ll sum,ll q){
	if(cnt==x){
		if(sum>mx*2) ans++;
		ans%=998244353;
	}
	else{
		for(ll i=q;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(x,cnt+1,max(mx,a[i]),sum+a[i],i+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=3;i<=n;i++) dfs(i,0,0,0,1); 
	cout<<ans;
	return 0;
}


