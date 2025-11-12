#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=10;
ll n,m;
ll a[N*N+5];
ll r;
bool cmp(ll l1,ll l2){
	return l1>l2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll sx=0;
	for(ll i=1;i<=m;i++){
		if(i&1){
			for(ll j=1;j<=n;j++){
				sx++;
				if(a[sx]==r){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}
		else{
			for(ll j=n;j>=1;j--){
				sx++;
				if(a[sx]==r){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
