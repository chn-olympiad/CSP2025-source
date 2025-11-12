#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
ll a[101];

string s;

bool cmp(ll a,ll b)
{
	return a > b;
}

int main( )
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;

	for(ll i = 1;i <= n * m;i ++)
	{
       cin>>a[i];
	}
	
	ll k = a[1];
	
	sort(a + 1,a + 1 + n * m,cmp);

	ll c = 0;
	bool f = true;
	for(ll i = 1;i <= m;i ++)
	{
		if(i % 2 == 1)
		{
			for(ll j = 1;j <= n;j ++)
			{
				c ++;
				if(k == a[c])
				{
					f = false;
					cout<<i<<" "<<j; 
					break;
				}
			}
		}
		else
		{
			for(ll j = n;j >= 1;j --)
			{
				c ++;
				if(k == a[c])
				{
					f = false;
					cout<<i<<" "<<j; 
					break;
				}
			}
		}
		if(f == false)
		{
			break;
		}
	}	

	return 0;
}
