#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],ans;
void dfs(ll st,ll t,ll sum,ll maxx,ll cnt){
	if(st==n+1){
		if(cnt<3) return ;
		if(sum>maxx*2) ans++;
		return ;
	}
	if(t==1){
		maxx=max(a[st],maxx);
		sum+=a[st];
	}
	dfs(st+1,0,sum,maxx,cnt);
	dfs(st+1,1,sum,maxx,cnt+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0,0);
	ans/=2;
	cout<<ans%998244353;
	return 0;
}