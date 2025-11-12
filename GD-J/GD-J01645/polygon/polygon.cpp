#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,mod=998244353;
ll n,m,cnt,a[N],b[N],vis[N];
void check(){
	ll sum=0,maxn=0;
	m=0;
	for(ll i=1;i<=n;i++){
		if(!vis[i]) sum+=a[i],m++,maxn=max(a[i],maxn);
	}
	if(m>=3&&sum>maxn*2) cnt++;
	return;
}
void dfs(ll x){
	if(x==n+1){
		check();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
