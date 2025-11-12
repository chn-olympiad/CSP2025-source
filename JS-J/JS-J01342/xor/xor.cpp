#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,ans,sum;

ll a[500001];

int main( )
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>k;
	for(ll i = 1;i <= n;i ++)
	{
		cin>>a[i];
	}
	                                                                                            
	for(ll i = 1;i <= n;i ++)
	{
		if(sum != 0)
		{
			sum = sum ^ a[i];
		}
		else
		{
			sum = a[i];
		}
		if(sum == k)
		{
			sum = 0;
			ans ++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
