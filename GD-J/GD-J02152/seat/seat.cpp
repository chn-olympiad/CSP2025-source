#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sz[110];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>sz[i];
	}
	ll a=sz[1],b,c,d;
	sort(sz+1,sz+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++)
	{
//		cout<<sz[i]<<' ';
		if(sz[i]==a) 
		{
			b=i;
			break;
		}
	}
	c=b/n+1;
	if(b%n==0) c--;
	d=b%n;
	if(d==0) d=n;
	cout<<c<<' ';
	if(c%2==0) cout<<(n-(d%(n+1)))+1;
	else cout<<d;
	return 0;
}

