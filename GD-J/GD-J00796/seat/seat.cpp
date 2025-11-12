#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ll ans=a[1];
	sort(a+1,a+1+n*m);
	for(ll i=n*m;i>=1;i--)
	{
		if(a[i]==ans)
		{
			ans=i;
			break ;
		}
			
	}
	ans=n*m-ans+1;
	ll x,y;
	x=ans/n;
	if(x*n!=ans)
		x++;
	if(x%2)
	{
		y=ans%n;
	}
	else
		y=n-ans%n+1;
	if(!y)
		y=n;
	cout<<x<<" "<<y;
}
