#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll lenth[5010];
ll ans=0,m;
bool visit[5010];
void dfs(ll cnt,ll k,ll n,ll a){
	if(k>m)return;
	if(cnt==0){
		if(a-n>n)ans++;
		return;
	}
	for(ll i = k+1; i<=m-cnt+1; i++){
		if(visit[i])continue;
		visit[i]=1;
		dfs(cnt-1,i,max(n,lenth[i]),a+lenth[i]);
		visit[i]=0;
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(ll i = 1; i <= m; i ++){
		cin>>lenth[i];
	}
	for(ll i = 3; i <= m; i ++){
		dfs(i,1,0,0);
	}
	cout<<ans;
	return 0;
} 
