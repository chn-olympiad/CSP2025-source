#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll a[n*m+1];
	for(ll i = 1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	ll c=a[1];
	sort(a+1,a+(n*m)+1);
	for(ll i = 1;i<=n*m;i++){
		if(a[i]==c){
			ll x=n*m-i+1;
			if(x%n!=0&&(x/n)%2==0)
				printf("%lld %lld",x/n+1,x%n);
			else if(x%n!=0&&(x/n)%2!=0)
				printf("%lld %lld",x/n+1,n-x%n+1);
			else if(x%n==0&&(x/n)%2==0)
				printf("%lld 1",x/n);
			else if(x%n==0&&(x/n)%2!=0)
				printf("%lld %lld",x/n,n);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
