#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353;
ll n,a[10010];
bool vis[10010];
ll dfs(ll d){
	ll ans=0;
	if(d==n+1){
		ll s=0,c=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) s+=a[i],c++,mx=max(mx,a[i]);
		}
		if(c>=3&&s>2*mx) return 1;
		else return 0;
	}
	vis[d]=true;
	ans+=dfs(d+1);
	vis[d]=false;
	ans+=dfs(d+1);
	return ans%p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	bool f=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) f=false;
	}
	if(f){
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*2%p;
		ans=(ans-n-1-n*(n-1)/2);
		ans=(ans%p+p)%p;
		cout<<ans;	
		return 0;
	}
	cout<<dfs(1); 
	return 0;
}
