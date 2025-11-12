#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(const ll &x,const ll &y){
	return x>y;
}
ll a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m*n;i++)cin>>a[i];
	ll x=a[1];
	sort(a+1,a+1+m*n,cmp);
	ll pos=-1;
	ll l=1,r=m*n+1;
	while(l<r){
		ll mid=(l+r)/2;
		if(a[mid]==x){pos=mid;break;}
		else if(a[mid]>x)l=mid+1;
		else r=mid;
	}
	ll len=ceil(pos*1.0/n);
	printf("%lld ",len);
	if(len%2==0)printf("%lld",len*n-pos+1);
	else printf("%lld",pos-(len-1)*n);
	return 0;
}
