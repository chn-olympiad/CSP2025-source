#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5005;
const ll mod=998244353;
ll n,a[maxn],A,c[maxn][maxn],ans;
void init(){
	c[0][0]=1;
	for(ll i=1;i<=n;i++){
		c[i][0]=1;
		for(ll j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	return ;
}
bool cmp(ll p,ll q){
	return p>q;
}
ll Max(ll a,ll b){
	return a>=b?a:b;
}
ll dfs(ll ma,ll i,ll sum,ll km){
	if(i==n+1){
		if(km<3||sum<=ma) return 0;
		return 1;
	}
	if(sum>ma){
		ll res=0;
		for(int j=Max(3-km,0);j<=n-i+1;j++) res=(res+c[n-i+1][j])%mod;
		return res;
	}
	return (dfs(ma,i+1,sum+a[i],km+1)+
			dfs(ma,i+1,sum,km))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n; A=1;
	init();
	for(ll i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1) A=0;
	}
	if(A){
		for(ll i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		}
		cout <<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		ans=(ans+dfs(a[i],i+1,0,1))%mod;
	} 
	cout <<ans;
	return 0;
}
