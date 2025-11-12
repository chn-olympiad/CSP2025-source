#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
ll n,m,a[N],R;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<ll>());
	
	for(ll i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			ll x=ceil(i*1.0/n),y;
			if(x%2==1) 
			{
				if(i%n!=0) y=i%n;
				else y=n;
			}
			else 
			{
				if(i%n!=0) y=n-i%n+1;
				else y=1; 
			}
			
			cout<<x<<' '<<y;
			return 0;
		}
	}
	
	
	
}
