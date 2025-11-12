#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	ll R=a[1];
	ll len=n*m;
	sort(a+1,a+len+1,cmp);
	bool f=0;
	ll x=1,y=1;
	if(R==a[1]){
		printf("%lld %lld",y,x);
		return 0;
	}
	for(ll i=2;i<=n*m;i++){
		if(!f) x++;
		else x--;
		if(x>n) f=!f,x--,y++;
		else if(x<1) f=!f,x++,y++;
		if(a[i]==R){
			printf("%lld %lld",y,x);
			break;
		}
		
	}
	return 0;
}
