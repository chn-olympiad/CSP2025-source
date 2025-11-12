#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[105],n,m,se[12][12],a1;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll k=1;
	for(ll i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(ll j=1;j<=n;j++)
			{
				if(a[k++]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(ll j=n;j>=1;j--)
			{
				if(a[k++]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
