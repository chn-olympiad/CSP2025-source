#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[102],sco;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	sco=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
//	for(ll i=1;i<=n*m;i++) cout<<a[i]<<' ';
//	cout<<'\n';
	ll pos=lower_bound(a+1,a+1+n*m,sco,greater<ll>())-a;
//	cout<<pos<<'\n';
	if(((pos-1)/n)&1) cout<<(pos-1)/n+1<<' '<<n-(pos-1)%n;
	else cout<<(pos-1)/n+1<<' '<<(pos-1)%n+1;
	return 0;
}
