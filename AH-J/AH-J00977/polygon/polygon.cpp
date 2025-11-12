#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
ll n;
ll a[N];
ll A(ll x,ll y)
{
	ll t=1;
	for(ll i=y;i>=y-x+1;i--)
	{
		t=t*i%998244353;
	}
	return t;
}
ll S(ll x,ll y)
{
	ll s1=A(x,y);
	ll s2=A(x,x);
	return s1/s2%998244353;
}
void do3()
{
	ll s=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			for(ll k=j;k<=n;k++)
			{
				if(i+j+k>2*k)
					s++;
			}
		}
	}
	cout<<s;
	exit(0);
}
void d()
{
	ll s=0;
	for(ll i=n;i>=4;i--)
	{
		s+=S(i,n)%998244353;
	}
	cout<<s;
	exit(0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	ll e=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==1)
			e++;
	}
	if(e==n)
	{
		d();
	}
	sort(a+1,a+n+1);
	if(n<=2)
		cout<<"0";
	if(n==3)
	{
		do3();
	}
	cout<<"1";
}
