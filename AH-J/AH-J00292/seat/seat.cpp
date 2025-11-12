#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200],sum,id;
bool ok;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	sum=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+1+n*m);
	for(ll i=1;i<=n;i++){
		ok=!ok;
		if(ok)
			for(ll j=1;j<=m;j++){
				if(a[++id]==sum){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		else
			for(ll j=m;j>0;j--){
				if(a[++id]==sum){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
	}
	return 0;
}
