#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=501;
ll n,m;
ll a[N];
ll vis[N];
ll ans;
string s;
void dfs(ll x,ll w,ll al){
	if(x==n+1){
		if(al>=m)ans++;
		return ;
	}
	for(ll i=n;i>=1;i--){
		if(vis[i]==1)continue;
		vis[i]=1;
		if(s[x-1]=='0'||a[i]<=w){
			dfs(x+1,w+1,al);
		}else{
			dfs(x+1,w,al+1);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
