#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=1e5+10;
ll a[MaxN],b[105][105],n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	for(ll i=1; i<=n*m; i++)
	{
		cin >>a[i];
	}
	ll k=a[1],t=0;
	sort(a+1,a+1+(n*m));
	for(ll i=n*m; i>=1; i--)
	{
		t++;
		if(a[i]==k) break;
	}
	ll cnt=0;
	for(ll i=1; i<=n; i++)
	{
		if(i%2==1)
		{
			for(ll j=1; j<=m; j++)
			{
				cnt++;
				b[i][j]=cnt;
			}
		}
		else if(i%2==0)
		{
			for(ll j=m; j>=1;j--)
			{
				cnt++;
				b[i][j]=cnt;
			}
		}
	}
	for(ll i=1; i<=n;i++)
	{
		for(ll j=1; j<=m; j++)
		{
			if(b[i][j]==t)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
