#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=110;
ll n,m,p,a[N];

bool cmp(ll a,ll b){return a>b;}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	ll total=n*m;
	for(ll i=1;i<=total;++i)
	{
		scanf("%lld",&a[i]);
		if(i==1) p=a[i];
	}
	sort(a+1,a+total+1,cmp);
	ll cnt=0;
	for(ll i=1;i<=total;++i) if(a[i]==p) cnt=i;
	ll x,y;
	y=(cnt-1)/n+1;
	if(!(y%2)) x=m-(cnt-(y-1)*n)+1;
	else x=cnt-(y-1)*n;
	printf("%lld %lld\n",y,x);
	return 0;
}
//8:58 T2+100
