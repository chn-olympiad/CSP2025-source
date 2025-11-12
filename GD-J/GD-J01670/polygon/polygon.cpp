#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=5e3+10;
const ll mod=998244353;
ll a[MaxN],n,k[MaxN*MaxN],m[MaxN*MaxN],zd,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3]) 
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else 
	{
		sort(a+1,a+1+n);
		ll k=0;
		if(a[n]==1)
		{
			for(ll i=3;i<=n;i++)
			{
				for(ll j=1;j<=i;j++)
				{
					k=(k*(n-j+1))%mod;
				}	
			}	
		}	
		cout<<k;
	}
	return 0;
}
