#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5000+10],ans=0,Max=INT_MIN;
void dfs(ll k,ll sum,ll Max){
	if(k==n+1){
		if(sum>Max*2) ans++;
		ans%=998244353;
		return ;
	}
	dfs(k+1,sum+a[k],max(Max,a[k]));
	dfs(k+1,sum,Max);
}
ll c(ll x,ll y){
	if(x==y) return 1;
	ll r=x-y;
	ll anss=1;
	if(r>y){
		for(ll i=r+1,j=1;i<=x;i++){
			anss*=i;
			if(j<y && anss%j==0) j++,anss/=j;
		}
	}
	else{
		for(ll i=y+1,j=1;i<=x;i++){
			anss*=i;
			if(j<r && anss%j==0) j++,anss/=j;
		}
	}
	anss%=998244353;
	return anss;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],Max=max(Max,a[i]);
	if(Max==1){
		for(ll i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}