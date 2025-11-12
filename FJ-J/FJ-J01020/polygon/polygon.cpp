#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
ll n,cnt,f;
ll a[5005];
ll s[5005];
void dfs(ll x){
	if(x>n){
		ll sum=0,ans=0,maxn=0;
		for(ll i=1;i<=n;i++){
			if(s[i]==1){
				ans++;
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(sum>maxn*2 && ans>=3) cnt++;
		cnt%=p;
		return;
	}
	s[x]=0;
	dfs(x+1);
	s[x]=1;
	dfs(x+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1) f=1;
	}
	sort(a+1,a+n+1);
	if(f==1){
		dfs(1);
		printf("%lld",cnt%p);
	}else{
		ll b=1;
		for(ll i=1;i<=n;i++){
			b*=2;
			b%=p;
		}
		printf("%lld",(b-1-n-n*(n-1)/2)%p);
	}
	return 0;
}
