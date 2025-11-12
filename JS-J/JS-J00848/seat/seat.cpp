#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,tmp=0;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	tmp=a[1];
	ll zb;
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++)
	{
		if(a[i]==tmp)
		{
			zb=i;
		}
	}
	ll r,c;
	r=ceil(zb*1.0/n);
	ll ans=zb-(r-1)*n;
	if(r%2==1)
	{
		c=ans;
	}
	else
	{
		c=n-ans+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
/*
*10 10
*1 2 3 4 5 6 7 8 9 10
*11 12 13 14 15 16 17 18 19 20
*21 22 23 24 25 26 27 28 29 30
* 31 32 33 34 35 36 37 38 39 40
* 41 42 43 44 45 46 47 48 49 50
* 51 52 53 54 55 56 57 58 59 60
* 61 62 63 64 65 66 67 68 69 70
* 71 72 73 74 75 76 77 78 79 80
* 81 82 83 84 85 86 87 88 89 90
* 91 92 93 94 95 96 97 98 99 100
*/
