#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll p=0,t=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			p++;
		if(a[i]==0)
			t++;
	}
	if(k==0&&p==n)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==1&&p+t==n)
	{
		cout<<p;
	}
	else if(k==0&&p+t==n)
	{
		cout<<p/2+t/2;
	}
}
