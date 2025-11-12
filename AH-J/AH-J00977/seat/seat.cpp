#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
ll n,m;
ll a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	ll k=a[1];
	sort(a+1,a+(n*m)+1,greater<int>() );
	for(ll i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(ll j=1;j<=m;j++)
			{
				if(a[(i-1)*m+j]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			
		}
		else
		{
			for(ll j=m;j>=1;j--)
			{
				if(a[(i-1)*m+(m-j+1)]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
