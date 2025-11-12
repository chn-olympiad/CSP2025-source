#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105;
struct node
{
	ll num,id;	
}a[N];
bool cmp(node x,node y)
{
	return x.num>y.num; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i].num);
		a[i].id=i; 
	}
	sort(a+1,a+1+n*m,cmp);
	ll ansx=1,ansy=1;
	for(ll i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			printf("%lld %lld",ansx,ansy);
			break;
		}
		if(ansx%2)
			ansy++;
		else
			ansy--;
		if(ansy>n||ansy<1)
		{
			ansx++;
			if(ansx%2)
				ansy++;
			else
				ansy--;
		}
	}
	return 0;
}
