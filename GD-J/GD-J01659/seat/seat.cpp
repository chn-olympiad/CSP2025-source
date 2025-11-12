#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,t;
ll a[10005];
bool cmp(ll i,ll j)
{
	return i>j;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll l;
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==t)
		{
			l=i;
			break;
		} 
	}
	ll x=0,y=0;
	x=(l+n-1)/n;
	if(x%2==1) y=(l-1)%n+1;
	else y=n-(l-1)%n;
	
	cout<<x<<" "<<y;
	
	
	return 0;
}


