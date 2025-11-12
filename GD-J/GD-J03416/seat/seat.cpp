#include<bits/stdc++.h>
#define ll long long
#define N 2000
using namespace std;

ll n,m,r,cnt=0;
ll a[N];

bool cmp(ll x,ll y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(r==a[cnt])
				{
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(r==a[cnt])
				{
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
	}
	return 0;
}
