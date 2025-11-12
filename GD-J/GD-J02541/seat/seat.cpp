#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[110];
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	ll x=n*m;
	ll cnt=x+1;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	ll k=a[1];
	sort(a+1,a+x+1);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				cnt--;
				if(a[cnt]==k) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				cnt--;
				if(a[cnt]==k) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}


