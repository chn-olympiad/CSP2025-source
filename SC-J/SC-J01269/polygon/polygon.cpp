#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
ll n,a[N],cnt,cnt1;
map<ll,ll>f[N];
void dfs(ll dit,ll x,ll xl,ll ans){
	if(xl==dit-1){
		cnt1+=f[x][ans];
		return ;
	}
	for(int i=x+1;i<=n;i++)
		dfs(dit,i,xl+1,ans+a[i]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		for(ll i=1;i<=n-2;i++) cnt+=i;
		cout<<cnt;
		return 0;
	}
	for(ll i=1;i<=n;i++)
		for(ll j=a[i]+1;j<=a[n]*2;j++)
			for(ll k=1;k<i;k++) 
				f[k][j]++;
	for(ll i=3;i<=n;i++){
		dfs(i,0,0,0);
	}
	cout<<cnt1;
	return 0;
} 