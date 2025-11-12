#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3;
ll n,m,a[N],t,v,addr;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if (i==1)v=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==v){
			addr=i;
		}
	}
	ll l=ceil((addr*1.0)/n);
	if (l%2==0){
		if (addr%n==0)printf("%lld %lld",l,1);
		else printf("%lld %lld",l,n-addr%n+1);
	}else if (l%2==1){
		if (addr%n==0)printf("%lld %lld",l,n);
		else printf("%lld %lld",l,addr%n);
	}
	return 0;
} 
