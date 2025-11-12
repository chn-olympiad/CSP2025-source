#include<bits/stdc++.h>
#define ll long long
#define N 5010
using namespace std;
ll n,ans;
ll p=998244353;
ll a[N],b[N][N];
void Yang_Hui() {
	b[1][1]=1;
	for(ll i=2; i<=n+1; i++)
		for(ll j=1; j<=i; j++)
			b[i][j]=(b[i-1][j]+b[i-1][j-1])%p;
	return ;
}
void go(ll zd,ll zh,ll xz) {
	if(xz==n+1) {
		if(zh>zd*2)
			ans++;
		return ;
	}
	go(zd,zh,xz+1);
	go(max(zd,a[xz]),zh+a[xz],xz+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1) {
		Yang_Hui();
		for(ll i=2; i<=n; i++)
			ans=(ans+b[n+1][i])%p;
		cout<<ans;
		return 0;
	} else if(n<=20) go(0,0,1);
	else ans=0;
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/