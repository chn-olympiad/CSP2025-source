#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5001;
ll n;
ll maxn,cnt;
ll ans;
ll a[N],vis[N];
void dfs(ll w,ll k){
	ll ww=maxn*2;
	if(k>=3&&cnt>ww)ans++;
	for(ll i=w;i<=n;i++){
		if(vis[i]==1)continue;
		ll kk=maxn;
		vis[i]=1;
		maxn=max(maxn,a[i]);
		cnt+=a[i];
		dfs(i+1,k+1);
		vis[i]=0;
		cnt-=a[i];
		maxn=kk;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		vis[i]=1;
		maxn=a[i],cnt=a[i];
		dfs(i+1,1);
		vis[i]=0;
	}
	cout<<ans%998244353;
	return 0;
}
