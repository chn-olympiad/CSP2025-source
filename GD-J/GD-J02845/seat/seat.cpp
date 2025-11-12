#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=110;
ll n,m,a[N]={0},t;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i],a[i]=-a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	ll p=lower_bound(a+1,a+1+n*m,t)-a;
	ll ans1=(p+n-1)/n;
	cout<<ans1<<' ';
	ll ans2=p-(p-1)/n*n;
	if(ans1&1) cout<<ans2<<' ';
	else cout<<n-ans2+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}
